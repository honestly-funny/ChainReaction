import java.util.Scanner;

/**
 * Created by sushr on 1/20/2018.
 */
public class Main {
    public static void main(String args[]){
        int gridLength = 0;
        int gridWidth = 0;

        while(gridLength < 1){
            Scanner in = new Scanner(System.in);
            System.out.println("What should the grid length be?");
            gridLength = in.nextInt();
        }
        while(gridWidth < 1){
            Scanner in = new Scanner(System.in);
            System.out.println("What should the grid width be?");
            gridWidth = in.nextInt();
        }

        Grid gameGrid = new Grid(gridLength, gridWidth);
        gameGrid.print();

        boolean win = false;
        int numPlayers = 0;
        while(numPlayers < 1 || numPlayers > 6){
            Scanner in = new Scanner(System.in);
            System.out.println("How many players are there?");
            numPlayers = in.nextInt();
        }
        Player[] players = new Player[numPlayers];
        for(int i = 0; i < numPlayers; i++){
            players[i] = new Player(i+1);
        }
        while(!win){
            for(Player player : players){
                System.out.println("It is Player " + player.player_id + "'s turn." );
                int x_coord = -1;
                int y_coord = -1;
                while(!gameGrid.isValidPlay(x_coord, y_coord, player.player_id)) {

                    Scanner in = new Scanner(System.in);
                    System.out.println("X coord of location?");
                    x_coord = in.nextInt();
                    System.out.println("Y coord of location?");
                    y_coord = in.nextInt();

                }
                gameGrid.execute_turn(x_coord, y_coord, player);
                gameGrid.print();
                win = gameGrid.checkForWin();
                if(win){
                    System.out.println("Player " + player.player_id + " won the game!");
                    break;
                }
            }

        }
    }
}
