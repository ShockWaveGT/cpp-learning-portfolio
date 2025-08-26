#include <iostream>
#include <map>
#include <string>
using namespace std;    

void ChooseAction(map<string , map<int, bool>>);
void ShowAllTasks(map<string , map<int, bool>>); 
map<string , map<int, bool>> SearchOrCreate(map<string , map<int, bool>>, string);

int main ()
{
    
    map<int, bool> taskInfo;
    
    map<string , map<int, bool>> task;
    
    ChooseAction(task);

    return 0;    
}

void ChooseAction(map<string , map<int, bool>> task)
{
    cout << "Choose how to continue" << endl;
    cout << "1: Search or Create Task" << endl;
    cout << "2: Show All Tasks" << endl;
    cout << "3: Shut down program" << endl;

    int keyIn;
    cin >> keyIn;
    
    
    switch(keyIn) {
        case 1:{
            cout << "Write which task to do you want to search information" << endl;
            string taskName;
            cin >> taskName;
    
            ChooseAction(SearchOrCreate(task, taskName));
            break;}
        case 2:{
            cout << "Searching all tasks information..." << endl;
            
            ShowAllTasks(task);
            ChooseAction(task);
            break;}
        case 3:{
        break;}};
        
};

map<string , map<int, bool>> SearchOrCreate(map<string , map<int, bool>> taskIn, string keyIn)
{
    
    if(taskIn.contains(keyIn) == 1)
    {
        for (auto& [taskId, bIsComplete]: taskIn [keyIn])
        {
            cout << "numero de tarea es: " << taskId << "\n" << "La tarea esta completada: " << bIsComplete << "\n";
        }
        return taskIn;
    }
    else
    {
        cout << "El mapa no contiene tu tarea, te la crearemos ahora" << endl;
        
        taskIn[keyIn].insert({ taskIn.size(), false});
        SearchOrCreate(taskIn, keyIn);
        cout << "\n";
        cout << "\n";
        
        return taskIn;
    }
        
}

void ShowAllTasks(map<string , map<int, bool>> taskIn)
{
    for (auto& [task, taskInfo]: taskIn)
    {
        cout << "Nombre de tarea " << task << "\n";

        for (auto& [taskId, bIsComplete]: taskInfo)
        {
            cout << "El numero de tarea es: " << taskId << "\n" << "La tarea esta completada: "<< bIsComplete << "\n";
            cout << "\n";
            cout << "\n";
        }
    }
}
