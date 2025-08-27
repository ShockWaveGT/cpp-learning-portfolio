#include <iostream>
#include <map>
#include <string>
using namespace std;    

enum ECompletionState{
    CREATED,
    STARTED,
    COMPLETED
    };

void ChooseAction(map<string , map<int, ECompletionState>>);
void ShowAllTasks(map<string , map<int, ECompletionState>>); 
map<string , map<int, ECompletionState>> SearchOrCreate(map<string , map<int, ECompletionState>>, string);

int main ()
{
    
    map<int, ECompletionState> taskInfo;
    
    map<string , map<int, ECompletionState>> task;
    
    ChooseAction(task);
    
    return 0;    
}

void ChooseAction(map<string , map<int, ECompletionState>> task)
{
    cout << "Choose how to continue" << endl;
    cout << "1: Search or Create Task" << endl;
    cout << "2: Show All Tasks" << endl;
    cout << "3: Change Completion State" << endl;
    cout << "4: Shut Down Program" << endl;

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
            cout << "Write which task to do you want to search information" << endl;
            string taskName;
            cin >> taskName;
    
            auto taskSelected = SearchOrCreate(task, taskName);
            
            cout << "Choose Completion State" << endl;
            cout << "1: Created" << endl;
            cout << "2: Started" << endl;
            cout << "3: Completed" << endl;

            int keyIn;
            cin >> keyIn;
            
            ECompletionState completionChoosed;
            switch(keyIn){
            case 1:{
                completionChoosed = ECompletionState::CREATED;
                break;}
            case 2:{
                completionChoosed = ECompletionState::STARTED;
                break;}
            case 3:{
                completionChoosed = ECompletionState::COMPLETED;
                break;}}
            
            for (auto& [taskId, completionStatus]: taskSelected [taskName])
            {
                taskSelected[taskName] = {{taskId, completionChoosed}};           
            };
            
            ChooseAction(taskSelected);
            break;}
        case 4:{
        break;}};
        
};

map<string , map<int, ECompletionState>> SearchOrCreate(map<string , map<int, ECompletionState>> taskIn, string taskName)
{
    
    if(taskIn.contains(taskName) == 1)
    {
        for (auto& [taskId, completionStatus]: taskIn [taskName])
        {
            cout << "numero de tarea es: " << taskId << "\n" << "La tarea esta completada: " << completionStatus << "\n";
        }
        return taskIn;
    }
    else
    {
        cout << "El mapa no contiene tu tarea, te la crearemos ahora" << endl;
        
        taskIn[taskName].insert({ taskIn.size(), ECompletionState::CREATED});
        SearchOrCreate(taskIn, taskName);
        cout << "\n";
        cout << "\n";
        
        return taskIn;
    }
        
}

void ShowAllTasks(map<string , map<int, ECompletionState>> taskIn)
{
    for (auto& [task, taskInfo]: taskIn)
    {
        cout << "Nombre de tarea " << task << "\n";

        for (auto& [taskId, completionStatus]: taskInfo)
        {
            cout << "El numero de tarea es: " << taskId << "\n" << "La tarea esta completada: "<< completionStatus << "\n";
            cout << "\n";
            cout << "\n";
        }
    }
}
