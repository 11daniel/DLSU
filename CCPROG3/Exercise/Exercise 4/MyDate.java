public class MyDate {
    private int year;
    private int month;
    private int day;


    public MyDate(){
		this(1950, 1, 1);
    }

    public MyDate(int month, int day){
		this(2023, month, day);
    }

    public MyDate(int year, int month, int day){
		this.year = year;
		this.month = month;
		this.day = day;
    }

    public boolean isBefore(MyDate givenDate){
        boolean check = false;

        if(this.year < givenDate.getYear()){
            check = true;
        }
        else{
            if(this.month < givenDate.getMonth()){
                check = true;
            }
            else{
                if(this.day < givenDate.getDay()){
                    check = true;
                }
            }
        }

        return check;
    }

    public void setDay(int day) {
        this.day = day;
    }

    public void setMonth(int month) {
        this.month = month;
    }

    public void setMonth(String month) {
        month = month.toLowerCase();
        switch(month){
            case "january": {this.month = 1; break;}
            case "february": {this.month = 2; break;}
            case "march": {this.month = 3; break;}
            case "april": {this.month = 4; break;}
            case "may": {this.month = 5; break;}
            case "june": {this.month = 6; break;}
            case "july": {this.month = 7; break;}
            case "august": {this.month = 8; break;}
            case "september": {this.month = 9; break;}
            case "october": {this.month = 10; break;}
            case "november": {this.month = 11; break;}
            case "december": {this.month = 12; break;}
        }
    }

    public void setYear(int year) {
        this.year = year;
    }

    public int getYear(){
        return this.year;
    }

    public int getMonth(){
        return this.month;
    }

    public int getDay(){
        return this.day;
    }

    public static void main(String[] args){
        MyDate date1 = new MyDate(2022, 9, 29);
        MyDate date2 = new MyDate(2022, 9, 28);
        MyDate date3 = new MyDate();
        MyDate date4 = new MyDate();

        System.out.println(date1.isBefore(date2)); // This should return false
        System.out.println(date2.isBefore(date1)); // This should return true
        System.out.println(date3.isBefore(date1)); // This should return true
        System.out.println(date3.isBefore(date4)); // This should return false
    }
}
