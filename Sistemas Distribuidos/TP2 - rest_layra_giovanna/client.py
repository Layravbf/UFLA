import requests
import json

url = "http://localhost:5000/tarefas"

myResponse = requests.get(url)

if(myResponse.ok):

    jData = json.loads(myResponse.content)

    for key, value in jData.items():
        if(type(value) == int):
            print("Foram encontradas {0} tarefas.".format(value))
        else:
            print("Tarefas: ")
            for i in value:
                print(i)
else:
  # If response code is not ok (200), print the resulting http error code with description
    myResponse.raise_for_status()