package solver;
/*
 * XYBox Class tracks the coordinates of the player and boxes
 */
public class XYBox 
{
    private int x;
    private int y;
    
    public XYBox(int x, int y)
    {
        this.x = x;
        this.y = y;
    }

    public int getX()
    {
        return x;
    }

    public int getY()
    {
        return y;
    }

    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }
}