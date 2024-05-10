package solver;

public class Goal
{
  private int row;
  private int column;

  public Goal(int row, int column)
  {
    this.row = row;
    this.column = column;
  }

  public boolean isGoal(int row, int column)
  {
    if(this.row == row && this.column == column)
      return true;
    else
      return false;
  }

  public int getRow()
  {
    return this.row;
  }

  public int getColumn()
  {
    return this.column;
  }

  public void displayRC()
  {
    System.out.println("Row: "+row+" Column: "+column);
  }
}