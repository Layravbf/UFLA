from itertools import count
from typing import Optional
from flask import Flask, request, jsonify
from flask_pydantic_spec import FlaskPydanticSpec, Response, Request
from pydantic import BaseModel, Field
from tinydb import TinyDB, Query

server = Flask(__name__)
spec = FlaskPydanticSpec('flask', title='Tarefas Api')
spec.register(server)
database = TinyDB('database.json')
c = count()

class Tarefa(BaseModel):
    id: Optional[int] = Field(default_factory=lambda: next(c))
    descricao: str
    prazo: str
    completa: bool

class Tarefas(BaseModel):
    tarefas: list[Tarefa]
    count: int

@server.get('/tarefas') #recurso
@spec.validate(resp=Response(HTTP_200=Tarefas))
def get_tarefas():
    """Retorna todas as tarefas da base de dados"""
    return jsonify(
        Tarefas(
            tarefas=database.all(),
            count=len(database.all())
        ).dict()
    )

@server.get('/tarefas/<int:id>') #recurso
@spec.validate(resp=Response(HTTP_200=Tarefa))
def get_tarefa(id):
    """Retorna tarefa da base de dados"""
    try:
        tarefa = database.search(Query().id == id)[0]
    except IndexError:
        return {'message': 'Tarefa nao encontrada!'}, 404
    return jsonify(tarefa)
    

@server.post('/tarefas')
@spec.validate(body=Request(Tarefa), resp=Response(HTTP_201=Tarefa))
def inserir_tarefa():
    """ Insere uma tarefa no banco de dados."""
    body = request.context.body.dict()
    database.insert(body)
    return body

@server.put('/tarefas/<int:id>')
@spec.validate(
    body=Request(Tarefa), resp=Response(HTTP_201=Tarefa)
)
def altera_tarefa(id):
    """Altera uma tarefa no banco de dados."""
    Tarefa = Query()
    body = request.context.body.dict()
    database.update(body, Tarefa.id == id)
    return jsonify(body)

@server.delete('/tarefas/<int:id>')
@spec.validate(resp=Response('HTTP_204'))
def deleta_tarefa(id):
    """Remove uma tarefa do banco de dados."""
    Tarefa = Query()
    database.remove(Tarefa.id == id)
    return jsonify({})

server.run()