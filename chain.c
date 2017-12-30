// NOT BEING USED ATM, i just forced it lol
int create_index; // will use to move index of array being used to store each element. should probably do this using malloc in c++. or maybe now its time i learn java. 

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
     
} element;


// Create each box, will need functions for corner, edge, and regulars. 
// --> Splitting so that it's easier to create different sized grids, and possibly user creates grids themselves. 

element create_corner(int corner_x, int corner_y) {
	
    element new_element; 
    
    new_element.x = corner_x; 
    new_element.y = corner_y; 
    new_element.corner = 1; 
    new_element.edge = 0; 
    new_element.normal = 0; 
    new_element.balls = 0; 
    new_element.player_id = 0; // There is no player on there atm. 

    return new_element; 

}

element create_edge(int edge_x, int edge_y) {
	
    element new_element; 
    
    new_element.x = edge_x; 
    new_element.y = edge_y; 
    new_element.corner = 0; 
    new_element.edge = 1; 
    new_element.normal = 0; 
    new_element.balls = 0; 
    new_element.player_id = 0; // There is no player on there atm. 

    return new_element;  
}

element create_normal(int normal_x, int normal_y) {
	

    element new_element; 
    
    new_element.x = normal_x; 
    new_element.y = normal_y; 
    new_element.corner = 0; 
    new_element.edge = 0; 
    new_element.normal = 1; 
    new_element.balls = 0; 
    new_element.player_id = 0; // There is no player on there atm. 

    return new_element; 
}


int main() {
	// Will build map here. 
    /* 3X3 attempt */
    element start[9]; 

    start[0] = create_corner(0,0);
    start[1] = create_corner(0,2); 
    start[2] = create_corner(2,0); 
    start[3] = create_corner(2,2); 
    start[4] = create_edge(0,1); 
    start[5] = create_edge(1,0); 
    start[6] = create_edge(1,2); 
    start[7] = create_edge(2,1); 
    start[8] = create_normal(1,1); 


	printf("Compile testing"); 
	return 0; 
}
