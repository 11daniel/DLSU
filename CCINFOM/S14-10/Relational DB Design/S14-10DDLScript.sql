
CREATE TABLE ref_file_types (
	filetype	INT(4),
	description	VARCHAR(45),
	primary key (filetype)
);

CREATE TABLE files (
	fileid		INT(4),
	filename	VARCHAR(45),
	description	VARCHAR(45),
	filelocation	VARCHAR(45),
	filetype	INT(4),
	submitdate	DATE,
	uploader	VARCHAR(45),
	primary key (fileid),
	foreign key (filetype) 
	references	ref_file_types (filetype),
	unique (filelocation, filename)
);

CREATE TABLE ref_coldays (
	day	INT(2),
	primary key (day)
);

CREATE TABLE hoa (
	name			VARCHAR(45),
	streetno		VARCHAR(45),
	aofincorporation_fileid	INT(4),
	bylaws_fileid		INT(4),
	minutesga_fileid	INT(4),
	regcolday		INT(2),
	primary key (name),
	foreign key (aofincorporation_fileid) 
	references	files (fileid),
	foreign key (bylaws_fileid) 
	references	files (fileid),
	foreign key (minutesga_fileid) 
	references	files (fileid),
	foreign key (regcolday) 
	references	ref_coldays (day)
);

CREATE TABLE homeowner (
	homeownerid		INT(4),
    hoaname			VARCHAR(45),
    yearasho		VARCHAR(45),
    expression		ENUM('Y','N'),
    primary key	(homeownderid)
);

CREATE TABLE zipcodes (
	barangay		VARCHAR(45),
    city			VARCHAR(45),
    province		VARCHAR(45),
    zipcode			INT(4),
    primary key (barangay),
    primary key (city),
    foreign key (province) 
	references	province (province)
);

CREATE TABLE  provinces (
	province 		VARCHAR(45),
    region			VARCHAR(45),
    primary key	(province)
);

CREATE TABLE commercial (
	propertycode 	VARCHAR(10),
    maximumtenants	INT(2),
    commercialtype	VARCHAR(45),
    foreign key (propertycode)  
	references	property (propertycode)
);

CREATE TABLE residential (
	propertycode 	VARCHAR(10),
    foreign key (propertycode)  
	references	property (propertycode)
);

CREATE TABLE property (
	propertycode	VARCHAR(45),
    size 			VARCHAR(45),
    turnoverdate	DATE,
    propertytype	ENUM('H','O'),
    primary key (propertycode)
);

CREATE TABLE ho_property (
	propertycode 	VARCHAR(10),
    homeownerid 	INT(4),
    classification	ENUM('R','C'),
    foreign key (propertycode) 
	references	property (propertycode),
	foreign key (homeownerid) 
	references	homeowner (homeownerid)
);

CREATE TABLE hoaproperty (
	propertycode 	VARCHAR(10),
    hoaname			VARCHAR(45),
    foreign key (propertycode) 
	references	property (propertycode),
	foreign key (hoaname) 
	references	hoa	(hoaname)
);

CREATE TABLE householdid (
	householdid		INT(4),
    propertycode 	VARCHAR(10),
    primary key (householdid),
    foreign key (propertycode) 
	references	property (propertycode)
);

CREATE TABLE person (
	personid		INT(4),
    birthday		DATE,
    gender			ENUM('M','F'),
    email 			VARCHAR(45),
    fburl			VARCHAR(45),
    picture			VARCHAR(45),
    undertaking		ENUM('Y','N'),
    primary key 	(personid)
);

CREATE TABLE person_mobile (
	personid		INT(4),
    mobileno		INT(12),
    primary key (mobileno),
    foreign key (personid) 
	references	person (personid)
);

CREATE TABLE person_name (
	personid		INT(4),
    lastname		VARCHAR(45),
    firstname		VARCHAR(45),
    middlename		VARCHAR(45),
    primary key	(personid)
);

CREATE TABLE asset  (
	assetid			INT(4),
    propertycode 	VARCHAR(10),
    assetname 		VARCHAR(45),
    description		VARCHAR(45),
    acquisitiondate	DATE,
    forrent			ENUM('Y','N'),
    value			DECIMAL(9,2),
    type			ENUM('P','E','F','O'),
    status			ENUM('W', 'D', 'R', 'P', 'S'),
    locx			VARCHAR(45),
    locy			VARCHAR(45),
    primary key (assetid),
    foreign key (propertycode)  
	references	property (propertycode)
);

CREATE TABLE contained_assets (
	assetid			INT(4),
    contained_assets	INT(4),
    foreign key (assetid)  
	references	asset (assetid),
	foreign key (contained_assets)  
	references	asset (assetid)
);

CREATE TABLE asset_activity (
	assetid			INT(4),
    actityno		INT(10),
    description		VARCHAR(45),
    location 		VARCHAR(45),
    startdate		DATE,
    enddate			DATE,
    cost			VARCHAR(45),
    officialreceipt	VARCHAR(45),
    status			ENUM('S', 'O', 'C', 'D'),
    primary key (activtyno),
    foreign key (assetid)  
	references	asset (assetid)
);

CREATE TABLE resident (
	residentid		INT(4),
    householdid		INT(4),
    isauthorized 	ENUM('Y','N'),
    renter			ENUM('Y','N'),
    relationship 	VARCHAR(45),
    lastupdatedate	DATE,
    foreign key (residentid)  
	references	person (personid),
	foreign key (householdid)  
	references	household (householdid)
);


CREATE TABLE rental (
	assetid			INT(4),
    residentid		INT(4),
    rentdate 		DATE,
    primary key (rentdate),
    foreign key (assetid)  
	references	asset (assetid),
	foreign key (residentid)  
	references	resident (residentid)
);

CREATE TABLE insider (
	personid		INT(4),
    plateno			VARCHAR(7),
    foreign key (personid)  
	references	person (personid),
	foreign key (plateno)  
	references	vehicle (plateno)
);

CREATE TABLE vehicle (
	plateno			VARCHAR(7),
    classification	VARCHAR(45),
    type			VARCHAR(45),
    orcr			VARCHAR(45),
	orcrupdated		ENUM('Y', 'N'),
	regdate			DATE,
    vehicleownership	ENUM('O', 'I'),
    primary key (plateno)
);

CREATE TABLE outsider (
	plateno			VARCHAR(7),
    lastname		VARCHAR(45),
    firstname		VARCHAR(45),
    middlename		VARCHAR(45),
    foreign key (plateno)  
	references	vehicle (plateno)
);

CREATE TABLE sticker (
	stickerid				INT(4),
    validityyear			DATE,
    plateno					VARCHAR(7),
    officer_homeownerid		VARCHAR(45),
    officer_position		ENUM('P', 'V', 'T', 'A', 'S'),
    officer_electiondate	DATE,
    primary key (stickerid),
    foreign key (plateno) 
	references	vehicle (plateno),
    foreign key (officer_homeownerid) 
	references	officer (officer_homeownerid),
	foreign key (officer_position) 
	references	officer (officer_position),
	foreign key (officer_electiondate) 
	references	officer (officer_electiondate)
);

CREATE TABLE officer (
	homeownerid		INT(4),
    position		ENUM('P', 'V', 'T', 'A', 'S'),
    electiondate	DATE,
    startdate 		DATE,
    enddate			DATE,
    availdays		VARCHAR(45),
    availtime		ENUM('M', 'A'),
    foreign key (homeownerid) 
	references	homeowner (homeownerid),
	foreign key (electiondater) 
	references	election (electiondate)
);

CREATE TABLE elections	(
	electiondate		DATE,
    venue				VARCHAR(45),
    quorum				ENUM('Y', 'N'),
    witness_lastname	VARCHAR(45),
    witness_firstname	VARCHAR(45),
    witness_middlename	VARCHAR(45),
    primary key (electiondate),
    foreign key (witness_lastname) 
	references	witness (lastname),
	foreign key (witness_firstname) 
	references	witness (firstname),
	foreign key (witness_middlename) 
	references	witness (middlename)
);

CREATE TABLE witness (
	lastname		VARCHAR(45),
    firstname		VARCHAR(45),
    middlename		VARCHAR(45),
    mobileno		VARCHAR(45),
    primary key (lastname),
    primary key (firstname),
    primary key (middlename)
);

CREATE TABLE authorizedofficer (
	authorized_officer		INT(4),
    officerhomeownerid		INT(4),
    officerelectiondate		DATE,
    foreign key (authorized_officer) 
	references	homeowner (homeownerid),
	foreign key (officerhomeownerid) 
	references	homeowner (homeownerid),
	foreign key (officerelectiondate) 
	references	election (electiondate)
);

CREATE TABLE residentidcard (
	cardno			INT(4),
    residentid		INT(4),
    cancelled		ENUM('Y', 'N'),
    requestdate		DATE,
    reason			VARCHAR(45),
    provideddate	DATE,
    authorized_officer		INT(4),
    officerhomeownerid		INT(4),
    officerelectiondate		DATE,
    primary key (cardno),
    foreign key (residentid)  
	references	person (personid),
    foreign key (authorized_officer) 
	references	homeowner (homeownerid),
	foreign key (officerhomeownerid) 
	references	homeowner (homeownerid),
	foreign key (officerelectiondate) 
	references	election (electiondate)
);

CREATE TABLE authorized_resident (
	residentid		INT(4),
    foreign key (residentid)  
	references	resident (residentid)
);

CREATE TABLE business (
	businessname VARCHAR(45),
	businessid INT(4) ,
	ownerid INT(4) ,
	isresident ENUM('Y', 'N'),
	streetno VARCHAR(45),
	streetname VARCHAR(45) ,
	barangay VARCHAR(45) ,
	city VARCHAR(45) ,
	province VARCHAR(45) ,
	region VARCHAR(45) ,
	zipcode VARCHAR(45) ,
	locx VARCHAR(45) ,
	locy VARCHAR(45) ,
	businessemail VARCHAR(45) ,
	description VARCHAR(45) ,
	businesstype ENUM('P', 'S', 'C') ,
	startdate DATE ,
	operatingschedule DATETIME ,
	website VARCHAR(45) ,
	permitcopy VARCHAR(45) ,
	permitexpirydate DATE ,
	officer_position ENUM('P', 'V', 'T', 'A', 'S') ,
	officer_homeownerid INT(4) ,
	enddate DATE ,
	billid INT(4) ,
	officer_electiondate DATE ,
	primary key (businessid),
    foreign key (officer_position)  
	references	officer (position),
	foreign key (officer_homeownerid)  
	references	officer (homeownerid),
    foreign key (billid)
    references billing (billID),
    foreign key (ownerid)
    references resident (residentid)
);

CREATE TABLE employee (
   employeeid INT(4) ,
   position VARCHAR(45) ,
   primary key (employeeid),
   foreign key (employeeid)  
	references	person (personid)
);

CREATE TABLE monthlydues (
  regulardues VARCHAR(45) ,
  monthlyduesid INT(4) ,
  billID INT(4) ,
  primary key (monthlyduesid),
  foreign key (billID)  
	references	billing (billID)
);

CREATE TABLE otherdues (
  otherduesid INT(4) ,
  penalty VARCHAR(45) NULL,
  damagedproperty VARCHAR(45) NULL,
  primary key (otherduesid),
    foreign key (otherduesid)
    references monthlydues (monthlyduesid)
);

CREATE TABLE billing (
  billID INT(4) ,
  unpaiddues VARCHAR(45) ,
  incentives VARCHAR(45) ,
  discounts VARCHAR(45) ,
  billmonth DATE ,
  billyear DATE ,
  amounttocollect FLOAT ,
  dategenerated DATE ,
  paymentid INT(4) ,
  collectionday DATE ,
  primary key (billID)
);

CREATE TABLE payment (
  dateofpayment DATE ,
  amountpaid DECIMAL(9,2) ,
  personpaid VARCHAR(45) ,
  receivingofficer INT(4),
  ornumber VARCHAR(45)  COMMENT 'This is a controlled\nvalue',
  billid INT(4) ,
  businessid INT(4) ,
  primary key (ornumber),
    foreign key (billid)
   references  billing (billID),
    foreign key (businessid)
    references business (businessid),
    foreign key (receivingofficer)
    references officer (homeownerid)
    );


CREATE TABLE ruleno (
  ruleno INT(4) ,
  primary key (ruleno)
  );

CREATE TABLE incidentreport (
  incidentID INT(4) ,
  incidentdate DATE ,
  description VARCHAR(45) ,
  personname VARCHAR(45) ,
  residentid INT(4) ,
  businessname VARCHAR(45) ,
  investigatingofficer INT(4) ,
  penaltyimposed VARCHAR(45) ,
  ruleno INT(4) ,
  secondingofficer INT(4) ,
  businessid INT(4) ,
  primary key (incidentID),
    foreign key (businessid)
     references business (businessid),
    foreign key (residentid)
    references resident (residentid),
    foreign key (investigatingofficer)
     references officer (homeownerid),
    foreign key (incidentID)
    references otherdues (otherduesid),
    foreign key (secondingofficer)
	references officer (homeownerid),
    foreign key (ruleno)
     references ruleno (ruleno)
    );

CREATE TABLE evidence (
  evidenceID INT(4) ,
  evidencename VARCHAR(45) ,
  evidencedescription VARCHAR(45) ,
  filenameevidence VARCHAR(45) ,
  residentsubmitted INT(4) ,
  acceptingofficer INT(4) ,
  dateofsubmission DATE ,
  incidentID INT(4) ,
  primary key (evidenceID),
    foreign key (incidentID)
    references incidentreport (incidentID),
    foreign key (acceptingofficer)
    references officer (homeownerid)
    );

CREATE TABLE full_payment (
	full_paymentid 		VARCHAR(45),
    primary key (full_paymentid),
    foreign key (full_paymentid) references 
		payment (ornumber)
);

CREATE TABLE partial_payemnt (
	partial_paymentid 		VARCHAR(45),
    primary key (partial_paymentid),
    foreign key (partial_paymentid) references 
		payment (ornumber)
);