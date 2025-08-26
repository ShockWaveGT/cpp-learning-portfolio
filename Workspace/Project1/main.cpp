#include <iostream>
#include <map>
#include <string>
using namespace std;    

void Suma(int, int);
void ShowAllTasks(); 
void SearchTaskInfo(map<string , map<int, bool>>, string);

int main ()
{
    
    map<int, bool> taskInfo;
    
    map<string , map<int, bool>> task;
    
    string x; 
    cout << "Escribe lo que queres buscar" << endl;
    cin >> x ;
    
    SearchTaskInfo(task, x);

    return 0;    
}

void Suma(int num1, int num2)
{
    int localtaskId;
    
    localtaskId = num1 + num2;
    
    cout << "Tu numero es: " << localtaskId << "\n";
}


void SearchTaskInfo(map<string , map<int, bool>> taskIn, string keyIn)
{
    
    if(taskIn.contains(keyIn) == 1)
    {
        for (auto& [taskId, bIsComplete]: taskIn [keyIn])
        {
            cout << "numero de tarea es: " << taskId << "\n" << "La tarea esta completada: " << bIsComplete << "\n";
        }
    }
    else
    {
        cout << "El mapa no contiene tu tarea, te la crearemos ahora" << endl;
        
        taskIn[keyIn].insert({ taskIn.size(), false});
        
        SearchTaskInfo(taskIn, keyIn);
    }
        
}

void ShowAllTasks(map<string , map<int, bool>> taskIn)
{
    for (auto& [task, taskInfo]: taskIn)
    {
        for (auto& [taskId, bIsComplete]: taskInfo)
        {
                cout << "El numero de tarea es: " << taskId << "\n" << "La tarea esta completada: "<< bIsComplete << "\n";
        }
    }
}
