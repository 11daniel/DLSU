class BankAccount
{
  private double CashBalance;
  private String AccountName;
  private String IdentificationNumber;
  public BankAccount ()
  {
	this.IdentificationNumber = "Null";
	this.AccountName = "No Name";
	this.CashBalance = 0;
  }
  public BankAccount (String IdentificationNumber, String AccountName, double
					  CashBalance)
  {
	this.IdentificationNumber = IdentificationNumber;
	this.AccountName = AccountName;
	this.CashBalance = CashBalance;
  }
  public String IdentificationNumber ()
  {
	return this.IdentificationNumber;
  }
  public String AccountName ()
  {
	return this.AccountName;
  }
  public double CashBalance ()
  {
	return this.CashBalance;
  }
  public String inquire ()
  {
	return this.IdentificationNumber + this.AccountName + this.CashBalance;
  }
}
