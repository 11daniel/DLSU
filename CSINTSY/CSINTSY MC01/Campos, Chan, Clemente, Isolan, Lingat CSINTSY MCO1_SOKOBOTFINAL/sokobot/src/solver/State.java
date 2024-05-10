package solver;

import java.lang.Math;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
/*
 * State class handles the computation of states, neighbors, and heuristic cost
 */

public class State {

    private int height;
    private int width;
    private XYBox player; // player coordinates
    private List<XYBox> boxes; // box coordinates
    private List<Goal> goals;  // goal coordinates
    private char[][] mapData;
    private char[][] itemsData;
    private int heuristic;
    private State parent;
    private String moveSequence;

    public State(int height, int width, char[][] mapData, char[][] itemsData) {
        this.height = height;
        this.width = width;
        this.player = findPlayer(itemsData);
        this.boxes = findBox(itemsData);
        this.goals = findGoal(mapData);
        this.mapData = mapData;
        this.itemsData = itemsData;
        this.heuristic = calculateHeuristic();
        this.parent = null;
        this.moveSequence = "";
    }

    public State(State parent, char move) {
        this.height = parent.getHeight();
        this.width = parent.getWidth();
        this.parent = parent;
        this.moveSequence = parent.getPath() + move;
        this.mapData = parent.getMap();
 
        char[][] updateData = computeNextState(parent, move);
        this.itemsData = new char[height][width];

        for (int i = 0; i < height; i++) 
        {
            for (int j = 0; j < width; j++) 
            {
                this.itemsData[i][j] = updateData[i][j];
            }
        }
        this.player = findPlayer(this.itemsData);
        this.boxes = findBox(this.itemsData);
        this.goals = parent.getGoal();
        this.heuristic = calculateHeuristic();
    }

    // HEURISTIC: MANHATTAN DISTANCE and number of open goals
    private int calculateHeuristic() {
        int cost = 0;
        int min;
        int openGoals = goals.size();
    
        for (XYBox box : boxes) {
            min = Integer.MAX_VALUE;
            for (Goal goal : goals) {
                int dist = manhattanDistance(box, goal);
                min = Math.min(min, dist);
            }
            cost += min;
        }
    
        cost += openGoals;
    
        return cost;
    }
    
    // manhattan distance: sum of distances between the x and y coordinates
    private int manhattanDistance(XYBox box, Goal goal) {
        return Math.abs(box.getX() - goal.getRow()) + Math.abs(box.getY() - goal.getColumn());
    }

    public boolean isGoalState() {
        int goalCount = 0;
    
        for (XYBox box : boxes) {
            for (Goal goal : goals) {
                if (box.getX() == goal.getRow() && box.getY() == goal.getColumn()) {
                    goalCount++;
                    break; //
                }
            }
        }
        return goalCount == goals.size();
    }
    
    private List<XYBox> findBox(char[][] itemsData) {
        List<XYBox> boxLocations = new ArrayList<>();
        for (int i = 0; i < height; i++) 
        {
            for (int j = 0; j < width; j++) 
            {
                if (itemsData[i][j] == '$' || itemsData[i][j] == '*')
                    boxLocations.add(new XYBox(i, j));
            }
        }
        return boxLocations;
    }

    private List<Goal> findGoal(char[][] mapData) {
        List<Goal> positions = new ArrayList<>();
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) 
            {
                if (mapData[i][j] == '.' || mapData[i][j] == '*') 
                    positions.add(new Goal(i, j));
            }
        }
        return positions;
    }
    
    private XYBox findPlayer(char[][] itemsData){

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) 
            {
                if (itemsData[i][j] == '@' || itemsData[i][j] == '+') 
                   return new XYBox(i, j);
            }
        }

        return null;
    }

    // Duplicate state
    private char[][] copyState(State parent) {
        char[][] newState = new char[height][width];
    
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) 
            {
                newState[i][j] = parent.getItemData()[i][j];
            }
        }
    
        return newState;
    }

    // Acknowledgment: This method was inspired by the computeState()
    // from GitHub: https://github.com/zzhongab/AI_Sokoban/blob/master/src/State.java
    private char[][] computeNextState(State parent, char move) {
        char[][] newState = copyState(parent);
    
        if (move == 'l') {
            if ((mapData[parent.getPlayer().getX()][parent.getPlayer().getY() - 1] == ' ' ||
                mapData[parent.getPlayer().getX()][parent.getPlayer().getY() - 1] == '.') &&
                newState[parent.getPlayer().getX()][parent.getPlayer().getY() - 1] != '$') 
            {
                newState[parent.getPlayer().getX()][parent.getPlayer().getY() - 1] = '@';
            } 
            else if (newState[parent.getPlayer().getX()][parent.getPlayer().getY() - 1] == '$') 
            {
                if (mapData[parent.getPlayer().getX()][parent.getPlayer().getY() - 2] == ' ' ||
                    mapData[parent.getPlayer().getX()][parent.getPlayer().getY() - 2] == '.') 
                {
                    newState[parent.getPlayer().getX()][parent.getPlayer().getY() - 1] = '@';
                    newState[parent.getPlayer().getX()][parent.getPlayer().getY() - 2] = '$';
                }
            }
        } 
        else if (move == 'd') 
        {
            if ((mapData[parent.getPlayer().getX() + 1][parent.getPlayer().getY()] == ' ' ||
                mapData[parent.getPlayer().getX() + 1][parent.getPlayer().getY()] == '.') &&
                newState[parent.getPlayer().getX() + 1][parent.getPlayer().getY()] != '$') 
            {
                newState[parent.getPlayer().getX() + 1][parent.getPlayer().getY()] = '@';
            } 
            else if (newState[parent.getPlayer().getX() + 1][parent.getPlayer().getY()] == '$') 
            {
                if (mapData[parent.getPlayer().getX() + 2][parent.getPlayer().getY()] == ' ' ||
                    mapData[parent.getPlayer().getX() + 2][parent.getPlayer().getY()] == '.') 
                {
                    newState[parent.getPlayer().getX() + 1][parent.getPlayer().getY()] = '@';
                    newState[parent.getPlayer().getX() + 2][parent.getPlayer().getY()] = '$';
                }
            }
        } 
        else if (move == 'u') 
        {
            if ((mapData[parent.getPlayer().getX() - 1][parent.getPlayer().getY()] == ' ' ||
                mapData[parent.getPlayer().getX() - 1][parent.getPlayer().getY()] == '.') &&
                newState[parent.getPlayer().getX() - 1][parent.getPlayer().getY()] != '$') {
    
                newState[parent.getPlayer().getX() - 1][parent.getPlayer().getY()] = '@';
            } 
            else if (newState[parent.getPlayer().getX() - 1][parent.getPlayer().getY()] == '$') 
            {
                if (mapData[parent.getPlayer().getX() - 2][parent.getPlayer().getY()] == ' ' ||
                    mapData[parent.getPlayer().getX() - 2][parent.getPlayer().getY()] == '.') 
                {
                    newState[parent.getPlayer().getX() - 1][parent.getPlayer().getY()] = '@';
                    newState[parent.getPlayer().getX() - 2][parent.getPlayer().getY()] = '$';
                }
            }
        } 
        else if (move == 'r') 
        {
            if ((mapData[parent.getPlayer().getX()][parent.getPlayer().getY() + 1] == ' ' ||
                mapData[parent.getPlayer().getX()][parent.getPlayer().getY() + 1] == '.') &&
                newState[parent.getPlayer().getX()][parent.getPlayer().getY() + 1] != '$') 
            {
                newState[parent.getPlayer().getX()][parent.getPlayer().getY() + 1] = '@';
            } 
            else if (newState[parent.getPlayer().getX()][parent.getPlayer().getY() + 1] == '$') 
            {
                if (mapData[parent.getPlayer().getX()][parent.getPlayer().getY() + 2] == ' ' ||
                    mapData[parent.getPlayer().getX()][parent.getPlayer().getY() + 2] == '.') 
                {
                    newState[parent.getPlayer().getX()][parent.getPlayer().getY() + 1] = '@';
                    newState[parent.getPlayer().getX()][parent.getPlayer().getY() + 2] = '$';
                }
            }
        }
    
        newState[parent.getPlayer().getX()][parent.getPlayer().getY()] = ' ';
        return newState;
    }
    
    // This checks the validity of move
    public boolean isValid(char move) {
        boolean flag = false;
    
        // initial coordinates
        int dx = 0; 
        int dy = 0;
    
        // player config
        if (move == 'l')
            dy = -1; // down
        else if (move == 'd')
            dx = 1; // right
        else if (move == 'u')
            dx = -1; // left
        else if (move == 'r')
            dy = 1; // up

        // assign player move
        int currentX = this.getPlayer().getX();
        int currentY = this.getPlayer().getY();
        int nextX = currentX + dx;
        int nextY = currentY + dy;
    
        char pos = mapData[nextX][nextY];
        char item = this.getItemData()[nextX][nextY];
    
        // modified conditions from initial isValid() made by BLIX
        if (pos != '#') {
            if (item == ' ') 
                flag = true;
            else if (item == '$') 
            {
                int newX = nextX + dx;
                int newY = nextY + dy;
                char nextPos = mapData[newX][newY];
                char nextItem = this.getItemData()[newX][newY];
    
                if (nextPos != '#' && nextItem != '$')
                    flag = true;
            }
        }
    
        return flag;
    }
    // DEADLOCK CONDITIONS
    // Acknowledgement: significance of deadlock detections
    // https://studenttheses.uu.nl/bitstream/handle/20.500.12932/25074/GPLG_Thesis_3840859_Jelle_Postma.pdf?sequence=2&isAllowed=y
    public boolean isDeadlock() {
        for (XYBox box : boxes) {
            int boxX = box.getX();
            int boxY = box.getY();

            if (isVerticalDeadlock(boxX, boxY) || isHorizontalDeadlock(boxX, boxY)) {
                return true;
            }
        }
        return false;
    }

    // if the player is surrounded with walls above and below
    private boolean isVerticalDeadlock(int boxX, int boxY) {
        if (itemsData[boxX - 1][boxY] == '#' && itemsData[boxX + 1][boxY] == '#') 
        {
            return true;
        }
        return false;
    }

    // if the player is surrounded with walls left and right
    private boolean isHorizontalDeadlock(int boxX, int boxY) {
        if (itemsData[boxX][boxY - 1] == '#' && itemsData[boxX][boxY + 1] == '#') 
        {
            return true;
        }
        return false;
    }

    // Acknowledgment: The hashCode() and equals() methods were adapted from code
    // obtained from the GitHub repository link: https://github.com/zzhongab/AI_Sokoban/blob/master/src/State.java
    // this prevents issues of equality checks, hash-based collections, and custom equality criteria in State class
    public int hashCode() {
        return moveString().hashCode() * heuristic * 2;
    }
    
    @Override
    public boolean equals(Object obj){
        if (this == obj) {
            return true;
        }
        if (obj == null || getClass() != obj.getClass()) {
            return false;
        }
        State other = (State) obj;
        return Arrays.deepEquals(itemsData, other.itemsData);
        
    }

    public int getHeight() {
        return height;
    }

    public int getHeuristic() {
        return heuristic;
    }

    public char[][] getItemData() {
        return itemsData;
    }

    public char[][] getMap() {
        return mapData;
    }

    public String getPath() {
        return moveSequence;
    }

    public State getParentNode() {
        return parent;
    }

    public int getWidth() {
        return width;
    }

    public XYBox getPlayer() {
        return player;
    }
    public List<XYBox> getBoxes() {
        return boxes;
    }

    public List<Goal> getGoal() {
        return goals;
    }

    // To return the solution path as a string in cmd 
    public String moveString(){
        String str = "";
        for (int i = 0; i < mapData.length; i++) 
        {
            for (int j = 0; j < mapData[0].length; j++)
                str += itemsData[i][j];
        }
        return str;
    }
}