
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

void create_corner(int corner_x, int corner_y) {
	
}

void create_edge(int edge_x, int edge_y) {
	
}

void create_normal(int normal_x, int normal_y) {
	
}


int main() {
	// Will build map here. 
	printf("Compile testing"); 
	return 0; 
}
