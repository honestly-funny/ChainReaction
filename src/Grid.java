import java.util.ArrayList;

/**
 * Created by sushr on 1/20/2018.
 */
public class Grid {
    public Position[][] points;
    public int[][] player_ids;
    Grid(int length, int width){
        points = new Position[length][width];
        player_ids = new int[length][width];
        for(int i = 0; i < points.length; i++) {
            for (int j = 0; j < points[0].length; j++) {
                player_ids[i][j] = 0;
                int maxBalls = findNeighbors(i, j).size();
                System.out.println(maxBalls);
                Position curPos = new Position(i, j, 0, maxBalls);
                points[i][j] = curPos;
            }
        }
    }

    void print(){
        for(int i = 0; i < points.length; i++) {
            for (int j = 0; j < points[0].length; j++) {
                switch (player_ids[i][j])
                {
                    case 1:
                        System.out.print(Color.ANSI_BLUE + " " + points[i][j].numBalls + " " + Color.ANSI_RESET);
                        break;
                    case 2:
                        System.out.print(Color.ANSI_RED + " " + points[i][j].numBalls + " " + Color.ANSI_RESET);
                        break;
                    case 3:
                        System.out.print(Color.ANSI_GREEN + " " + points[i][j].numBalls + " " + Color.ANSI_RESET);
                        break;
                    case 4:
                        System.out.print(Color.ANSI_CYAN + " " + points[i][j].numBalls + " " + Color.ANSI_RESET);
                        break;
                    case 5:
                        System.out.print(Color.ANSI_PURPLE + " " + points[i][j].numBalls + " " + Color.ANSI_RESET);
                        break;
                    case 6:
                        System.out.print(Color.ANSI_YELLOW + " " + points[i][j].numBalls + " " + Color.ANSI_RESET);
                        break;
                    default:
                        System.out.print(Color.ANSI_BLACK + " " + points[i][j].numBalls + " " + Color.ANSI_RESET);
                }

            }
            System.out.println();
        }
    }

    ArrayList<Position> findNeighbors(int x, int y){
        ArrayList<Position> neighbors = new ArrayList<>();
        Position curPos = points[x][y];
        for(int i = -1; i <= 2; i+=2){
            if((x + i) >= points.length || (x + i) < 0){
                continue;
            }
            else{
                neighbors.add(points[x + i][y]);
            }
        }
        for(int i = -1; i <= 2; i+=2){
            if((y + i) >= points[0].length || (y + i) < 0){
                continue;
            }
            else{
                neighbors.add(points[x][y + i]);
            }
        }
        return neighbors;
    }

    boolean isValidPlay(int x, int y, int player_id){
        if(x < 0 || x >= points.length) return false;
        if(y < 0 || y >= points[0].length) return false;

        if(player_ids[x][y] != player_id && player_ids[x][y] != 0) return false;
        return true;

    }

    void execute_turn(int x, int y, Player player){
        Position chosenPos = points[x][y];
        player_ids[x][y] = player.player_id;
        chosenPos.numBalls++;
        if(chosenPos.numBalls >= chosenPos.maxBalls){
            explode(chosenPos, player);
        }
    }

    void explode(Position curPos, Player player){
        curPos.numBalls = 0;
        player_ids[curPos.x][curPos.y] = 0;
        ArrayList<Position> neighbors = findNeighbors(curPos.x, curPos.y);
        for(Position neighbor : neighbors){
            execute_turn(neighbor.x, neighbor.y, player);
        }
    }

    boolean checkForWin(){
        int winner_id = 0;
        int squares_controlled = 0;
        boolean foundPlayer = false;
        for(int i = 0; i < points.length; i++) {
            for (int j = 0; j < points[0].length; j++) {
                if(player_ids[i][j] != 0 && !foundPlayer){
                    foundPlayer = true;
                    winner_id = player_ids[i][j];
                    squares_controlled++;
                }
                else if(foundPlayer && player_ids[i][j] != winner_id && player_ids[i][j] != 0){
                    return false;
                }
                else if(foundPlayer && player_ids[i][j] == winner_id){
                    squares_controlled++;
                }
            }
        }
        if(squares_controlled <= 1){
            return false;
        }
        return true;
    }

}
