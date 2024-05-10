
CREATE DATABASE IF NOT EXISTS `salesdb`;
USE salesdb;
-- edit insert intos and add your own values - carlo
CREATE TABLE supplier (
	supplierid 		INT(4),
    name 			VARCHAR(45),
    streetno 		VARCHAR(45),
    barangay		VARCHAR(45),
    city			VARCHAR(45),
    province		VARCHAR(45),
    region			VARCHAR(45),
    zipcode			INT(4),
    estabyear		DATE,
    product_catalog	INT(4),
    primary key (supplierid)
    );
    
    -- INSERT INTO supplier (supplierid,name, streetno, barangay, city, province,region,zipcode,estabyear,product_catalog)
		-- VALUES();
   
   
    CREATE TABLE person(
        personID 		INT(4),
        lastname 		VARCHAR(45),
        firstname 		VARCHAR(45),
        primary key		(personID)
	);
    
    -- INSERT INTO person (personID,lastname,firstname)
		-- VALUES();
        
   CREATE TABLE product(
	productnum 	INT(4),
	product_type 	ENUM('F', 'NF'),
	productprice 	INT(6),
	product_supply 	INT(6),
	supplier 		INT(6),
	status 			ENUM('S', 'NS', 'D'),
	revenueearned 	INT(6),
	primary key(productnum),
	foreign key(supplier) REFERENCES
	supplier(supplierid)
	);     
    
    -- INSERT INTO product( `productnum`,`product_type`,`productprice`,`product_supply`,`supplier`,`status`,`revenueearned`)
		-- VALUES();
	
	CREATE TABLE salesrep(
	salesrepid  INT(4),
	personid    INT(4),
	totalsales  VARCHAR(45),
	supplier  INT(4),
	primary key (salesrepid),
	foreign key(supplier) REFERENCES
	supplier(supplierid),
	foreign key(personid) REFERENCES
	person(personid)
    );

-- INSERT INTO salesrep( `salesrepid`,`personid`,`totalsales`,`supplier`)
	-- VALUES();
    
	CREATE TABLE customer(
	customerid INT(4),
    salesrepid INT(4),
    personid INT(4),
	primary key(customerid),
	foreign key(personid) REFERENCES
	person(personid),
	foreign key(salesrepid) REFERENCES
	salesrep(salesrepid)
    );
    
-- INSERT INTO customer(customerid,salesrepid,personid)
	-- VALUES();
    
CREATE TABLE invoice(
	invoicenum				INT(4),
	productid 				INT(4),
	quantity 				INT(6),
	totalamountofpayment	INT(6),
	status 					ENUM('P', 'NP', 'D'),
	salesrepid			 	INT(4),
	customerid				INT(4),
  primary key (invoicenum),
  foreign key (salesrepid) REFERENCES
	salesrep(salesrepid),
  foreign key (customerid) REFERENCES
	customer(customerid)
);

-- INSERT INTO	invoice(`invoicenum`,`productid`,`quantity`,`totalamountofpayment`,`status`,`salesrepid`,`customerid`)
	-- VALUES();
	CREATE TABLE payment(
	paymentnum 		INT(4),
	amount 			INT(4),
	dateofpayment 	DATE,
	refund 			INT(4),
	invoicenum 		INT(4),
	customer		INT(4),
	primary key (paymentnum),
	foreign key (invoicenum) REFERENCES
	invoice(invoicenum),
	foreign key (customer) REFERENCES
	customer(customerid)
);
  
-- INSERT INTO payment(`paymentnum`,`amount`,`dateofpayment`,`refund`,`invoicenum`,`customer`)
	-- VALUES();