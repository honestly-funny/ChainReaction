#include<iostream>
#include<queue>
using namespace std;

// NOT BEING USED ATM, i just forced it lol
int create_index; // will use to move index of array being used to store each element. should probably do this using malloc in c++. or maybe now its time i learn java. 

queue<int> q; 


int x_max; 
int y_max; 

typedef struct element { 
    /*positions*/
    int x;
    int y; 
    /*type*/
    int corner; 
    int edge; 
    int normal; 
    /*number of active balls in element */
    int balls; 
    /*player to whom the balls belong to*/
    int player_id; 

    /* O(1) magic */ 
    int id; 
    int up_id; 
    int down_id; 
    int left_id; 
    int right_id; 
    
} element;

// typedef struct block {
//     element curr_element; 
//     element up_element; 
//     element down_element; 
//     element left_element; 
//     element right_element; 
// }block; 

element start[9]; 

int find_element(int given_x, int given_y){
    int i = 0; 
    for (i = 0; i < sizeof(start); i++){
        if (start[i] != NULL){
            if (start[i].x == given_x && start[i].y == given_y)
                return start[i].id;
        } 
    }
    return -1; 
}


// Create each box, will need functions for corner, edge, and regulars. 
// --> Splitting so that it's easier to create different sized grids, and possibly user creates grids themselves. 

element create_corner(int corner_x, int corner_y, int item_id) {
	
    element new_element; 
    
    new_element.x = corner_x; 
    new_element.y = corner_y; 
    new_element.corner = 1; 
    new_element.edge = 0; 
    new_element.normal = 0; 
    new_element.balls = 0; 
    new_element.player_id = 0; // There is no player on there atm. 
    new_element.id = item_id; 
    

    new_element.up_id    = find_element(corner_x, corner_y+1);
    new_element.down_id  = find_element(corner_x, corner_y-1); 
    new_element.left_id  = find_element(corner_x-1, corner_y); 
    new_element.right_id = find_element(corner_x+1, corner_y);  


    return new_element; 

}

element create_edge(int edge_x, int edge_y, int item_id) {
	
    element new_element; 
    
    new_element.x = edge_x; 
    new_element.y = edge_y; 
    new_element.corner = 0; 
    new_element.edge = 1; 
    new_element.normal = 0; 
    new_element.balls = 0; 
    new_element.player_id = 0; // There is no player on there atm. 
    new_element.id = item_id; 

    new_element.up_id    = find_element(edge_x, edge_y+1);
    new_element.down_id  = find_element(edge_x, edge_y-1); 
    new_element.left_id  = find_element(edge_x-1, edge_y); 
    new_element.right_id = find_element(edge_x+1, edge_y);  

    return new_element;  
}

element create_normal(int normal_x, int normal_y, int item_id) {
	

    element new_element; 
    
    new_element.x = normal_x; 
    new_element.y = normal_y; 
    new_element.corner = 0; 
    new_element.edge = 0; 
    new_element.normal = 1; 
    new_element.balls = 0; 
    new_element.player_id = 0; // There is no player on there atm. 
    new_element.id = item_id; 

    // A normal element will have access to at least its 4 up, down, left, right members. 
    new_element.up_id    = find_element(normal_x, normal_y+1);
    new_element.down_id  = find_element(normal_x, normal_y-1); 
    new_element.left_id  = find_element(normal_x-1, normal_y); 
    new_element.right_id = find_element(normal_x+1, normal_y);  
    
    return new_element; 
}

void redo_board(element element_todo){
    // Person has pressed on this element, error checking happens elsewhere. 

    //Three subcases depending on position 
    element_todo.balls++; 
    if ( (element_todo.corner == 1 && element_todo.balls == 1) ||
         (element_todo.edge == 1 && element_todo.balls <= 2) ||
         (element_todo.normal == 1 && element_todo.balls <= 3) )
       {    
        update_board(); 
       }

   else{ // explode. 
            if (element_todo.up_id != -1){
                q.push(element_todo.up_id); 
            }
            if (element_todo.down_id != -1){
                q.push(element_todo.down_id); 
            }
            if (element_todo.left_id != -1){
                q.push(element_todo.left_id); 
            }
            if (element_todo.right_id != -1){
                q.push(element_todo.right_id); 
            }

       }
}


void update_remaining_processes(int change_player_id) {
    // pseudo code --> 
    while(!q.empty()){
        int index = q.pop(); 
        element temp = start[index]; 
        temp.player_id = change_player_id; 
        redo_board(temp); 
    }
}

void user_input() {
    int global_player = 2; 
    int input; 
    while (1){

        /*Player switching, looking into mod for multi players*/
        if (global_player == 1)
            global_player == 2;
        else 
            global_player == 1; 

        cin >> input; 

        if (input < 0)
            break; 
        
        element to_use = start[input]; 
        q.push(to_use); 
        update_remaining_processes(global_player); 

    }


}

int main() {
	// Will build map here. 
    /* 3X3 attempt */

    start[0] = create_corner(0,0,0);
    start[1] = create_corner(0,2,1); 
    start[2] = create_corner(2,0,2); 
    start[3] = create_corner(2,2,3); 
    start[4] = create_edge(0,1,4); 
    start[5] = create_edge(1,0,5); 
    start[6] = create_edge(1,2,6); 
    start[7] = create_edge(2,1,7); 
    start[8] = create_normal(1,1,8); 


    x_max = 2; 
    y_max = 2; 

	cout << "Compile testing"; 

    user_input(); 
	return 0; 
}
