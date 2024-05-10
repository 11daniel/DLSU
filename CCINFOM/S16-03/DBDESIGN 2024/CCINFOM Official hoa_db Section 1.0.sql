-- -----------------------------------------------------
-- Schema hoa_db
-- -----------------------------------------------------
DROP SCHEMA IF EXISTS hoa_db;
CREATE SCHEMA IF NOT EXISTS hoa_db;
USE hoa_db;

-- -----------------------------------------------------
-- Table regions
-- -----------------------------------------------------
DROP TABLE IF EXISTS regions;
CREATE TABLE IF NOT EXISTS regions (
  region		VARCHAR(45) NOT NULL,
  PRIMARY KEY	(`region`)
);

-- -----------------------------------------------------
-- Table provinces
-- -----------------------------------------------------
DROP TABLE IF EXISTS provinces;
CREATE TABLE IF NOT EXISTS provinces (
  province_name VARCHAR(45) NOT NULL,
  region 		VARCHAR(45) NOT NULL,
  PRIMARY KEY 	(province_name),
  INDEX 		(region ASC),
  FOREIGN KEY	(region)
    REFERENCES	regions(region)
);

-- -----------------------------------------------------
-- Table cities
-- -----------------------------------------------------
DROP TABLE IF EXISTS cities;
CREATE TABLE IF NOT EXISTS cities (
  city			VARCHAR(45) NOT NULL,
  province		VARCHAR(45) NOT NULL,
  PRIMARY KEY	(city),
  INDEX			(province ASC),
  FOREIGN KEY	(province)
    REFERENCES	provinces(province_name)
);

-- -----------------------------------------------------
-- Table zipcodes
-- -----------------------------------------------------
DROP TABLE IF EXISTS zipcodes;
CREATE TABLE IF NOT EXISTS zipcodes (
  zipcode		INT NOT NULL,
  brgy			VARCHAR(45) NOT NULL,
  city			VARCHAR(45) NOT NULL,
  province		VARCHAR(45) NOT NULL,
  PRIMARY KEY	(zipcode),
  INDEX			(city ASC),
  INDEX			(province ASC),
  FOREIGN KEY	(city)
    REFERENCES	cities(city),
  FOREIGN KEY	(province)
    REFERENCES	provinces(province_name)
);

-- -----------------------------------------------------
-- Table address
-- -----------------------------------------------------
DROP TABLE IF EXISTS address;
CREATE TABLE IF NOT EXISTS address (
  address_id	INT NOT NULL,
  stno			VARCHAR(45) NOT NULL,
  stname		VARCHAR(45) NOT NULL,
  brgy			VARCHAR(45) NOT NULL,
  city			VARCHAR(45) NOT NULL,
  province		VARCHAR(45) NOT NULL,
  zipcode		INT NOT NULL,
  x_coord		FLOAT NOT NULL,
  y_coord		FLOAT NOT NULL,
  PRIMARY KEY	(address_id),
  INDEX			(city ASC),
  INDEX			(province ASC),
  INDEX			(zipcode ASC),
  FOREIGN KEY	(city)
    REFERENCES	cities(city),
  FOREIGN KEY	(province)
    REFERENCES	provinces(province_name),
  FOREIGN KEY	(zipcode)
    REFERENCES	zipcodes(zipcode)
);

-- -----------------------------------------------------
-- Table hoa
-- -----------------------------------------------------
DROP TABLE IF EXISTS hoa;
CREATE TABLE IF NOT EXISTS hoa (
  hoa_name			VARCHAR(45) NOT NULL,
  office_add		INT NOT NULL,
  year_est			INT(4) NOT NULL,
  website			VARCHAR(45) NULL,
  subd_name			VARCHAR(45) NOT NULL,
  dues_collection	VARCHAR(45) NOT NULL,
  PRIMARY KEY		(hoa_name),
  UNIQUE INDEX		(subd_name ASC),
  INDEX				(office_add ASC),
  FOREIGN KEY		(office_add)
    REFERENCES		address(address_id)
);

-- -----------------------------------------------------
-- Table individual
-- -----------------------------------------------------
DROP TABLE IF EXISTS individual;
CREATE TABLE IF NOT EXISTS individual (
  individual_id		INT NOT NULL,
  indiv_lastname	VARCHAR(45) NOT NULL,
  indiv_firstname	VARCHAR(45) NOT NULL,
  indiv_mi			VARCHAR(45) NOT NULL,
  email				VARCHAR(45) NOT NULL,
  birthday			DATE NOT NULL,
  gender			ENUM('M', 'F') NOT NULL,
  fb_url			VARCHAR(45) NULL,
  picture			BLOB NOT NULL,
  indiv_type		ENUM('R', 'H', 'HR') NOT NULL,
  PRIMARY KEY		(individual_id),
  UNIQUE INDEX		(email ASC),
  UNIQUE INDEX		(fb_url ASC)
);

-- -----------------------------------------------------
-- Table homeowner
-- -----------------------------------------------------
DROP TABLE IF EXISTS homeowner;
CREATE TABLE IF NOT EXISTS homeowner (
  homeowner_id	INT(5) NOT NULL,
  years_ho		INT(2) NOT NULL,
  undertaking	TINYINT(1) NOT NULL,
  membership	TINYINT(1) NOT NULL,
  is_resident	TINYINT(1) NOT NULL,
  current_add	INT NOT NULL,
  other_add		INT NULL,
  other_email	VARCHAR(45) NULL,
  hoa_name		VARCHAR(45) NOT NULL,
  individual_id	INT NOT NULL,
  PRIMARY KEY	(homeowner_id),
  INDEX			(hoa_name ASC),
  INDEX			(current_add ASC),
  INDEX			(other_add ASC),
  INDEX			(individual_id ASC),
  FOREIGN KEY	(hoa_name)
    REFERENCES	hoa(hoa_name),
  FOREIGN KEY	(current_add)
    REFERENCES	address(address_id),
  FOREIGN KEY	(other_add)
    REFERENCES	address(address_id),
  FOREIGN KEY	(individual_id)
    REFERENCES	individual(individual_id)
);

-- -----------------------------------------------------
-- Table officer_positions
-- -----------------------------------------------------
DROP TABLE IF EXISTS officer_positions;
CREATE TABLE IF NOT EXISTS officer_positions (
  position_name	VARCHAR(25) NOT NULL,
  PRIMARY KEY	(position_name)
);

-- -----------------------------------------------------
-- Table elections
-- -----------------------------------------------------
DROP TABLE IF EXISTS elections;
CREATE TABLE IF NOT EXISTS elections (
  elec_date			DATE NOT NULL,
  venue				VARCHAR(45) NOT NULL,
  quorum			TINYINT(1) NOT NULL,
  witness_lastname	VARCHAR(45) NOT NULL,
  witness_firstname	VARCHAR(45) NOT NULL,
  witness_mi		VARCHAR(45) NOT NULL,
  witness_mobile	BIGINT(10) NOT NULL,
  hoa_name			VARCHAR(45) NOT NULL,
  PRIMARY KEY		(elec_date),
  FOREIGN KEY		(hoa_name)
    REFERENCES		hoa(hoa_name)
);

-- -----------------------------------------------------
-- Table hoa_officer
-- -----------------------------------------------------
DROP TABLE IF EXISTS hoa_officer;
CREATE TABLE IF NOT EXISTS hoa_officer (
  officer_id	INT(5) NOT NULL,
  homeowner_id	INT(5) NOT NULL,
  position_name	VARCHAR(25) NOT NULL,
  office_start	DATE NOT NULL,
  office_end	DATE NOT NULL,
  elec_date		DATE NOT NULL,
  PRIMARY KEY	(officer_id),
  INDEX			(homeowner_id ASC),
  INDEX			(position_name ASC),
  INDEX			(elec_date ASC),
  FOREIGN KEY	(homeowner_id)
    REFERENCES	homeowner(homeowner_id),
  FOREIGN KEY	(position_name)
    REFERENCES	officer_positions(position_name),
  FOREIGN KEY	(elec_date)
    REFERENCES	elections(elec_date)
);

-- -----------------------------------------------------
-- Table hoa_files
-- -----------------------------------------------------
DROP TABLE IF EXISTS hoa_files;
CREATE TABLE IF NOT EXISTS hoa_files (
  file_id			INT NOT NULL,
  file_name			VARCHAR(45) NOT NULL,
  description		VARCHAR(45) NOT NULL,
  location			VARCHAR(45) NOT NULL,
  file_type			ENUM('document', 'spreadsheet', 'pdf', 'image', 'others') NOT NULL,
  date_submitted	DATETIME NOT NULL,
  file_owner		VARCHAR(45) NOT NULL,
  file_uploader		INT(5) NOT NULL,
  hoa_name			VARCHAR(45) NOT NULL,
  PRIMARY KEY		(file_id),
  INDEX				(hoa_name ASC),
  INDEX				(file_uploader ASC),
  FOREIGN KEY		(hoa_name)
    REFERENCES		hoa(hoa_name),
  FOREIGN KEY		(file_uploader)
    REFERENCES		hoa_officer(officer_id)
);

-- -----------------------------------------------------
-- Table property
-- -----------------------------------------------------
DROP TABLE IF EXISTS property;
CREATE TABLE IF NOT EXISTS property (
  property_code		VARCHAR(6) NOT NULL,
  size				DECIMAL NOT NULL,
  turnover			DATE NOT NULL,
  property_type		ENUM('R', 'C') NOT NULL,
  homeowner_id		INT(5) NOT NULL,
  PRIMARY KEY		(property_code),
  INDEX				(homeowner_id ASC),
  FOREIGN KEY		(homeowner_id)
    REFERENCES		homeowner(homeowner_id)
);


-- -----------------------------------------------------
-- Table household
-- -----------------------------------------------------
DROP TABLE IF EXISTS household;
CREATE TABLE IF NOT EXISTS household (
  household_id		INT(5) NOT NULL,
  PRIMARY KEY		(household_id)
);

-- -----------------------------------------------------
-- Table resident
-- -----------------------------------------------------
DROP TABLE IF EXISTS resident;
CREATE TABLE IF NOT EXISTS resident (
  resident_id			INT(5) NOT NULL,
  is_renter				TINYINT(1) NOT NULL,
  relation_ho			VARCHAR(45) NOT NULL,
  undertaking			TINYINT(1) NOT NULL,
  household_id			INT(5) NOT NULL,
  authorized_resident	TINYINT(1) NOT NULL,
  individual_id			INT NOT NULL,
  PRIMARY KEY			(resident_id),
  INDEX					(household_id ASC),
  INDEX					(individual_id ASC),
  FOREIGN KEY			(household_id)
    REFERENCES			household(household_id),
  FOREIGN KEY			(individual_id)
    REFERENCES			individual(individual_id)
);

-- -----------------------------------------------------
-- Table receipt
-- -----------------------------------------------------
DROP TABLE IF EXISTS receipt;
CREATE TABLE IF NOT EXISTS receipt (
  or_no			INT NOT NULL,
  transact_date DATETIME NOT NULL,
  total_amount	FLOAT NOT NULL,
  PRIMARY KEY	(or_no)
);

-- -----------------------------------------------------
-- Table resident_idcard
-- -----------------------------------------------------
DROP TABLE IF EXISTS resident_idcard;
CREATE TABLE IF NOT EXISTS resident_idcard (
  resident_idcardno		VARCHAR(10) NOT NULL,
  date_requested		DATETIME NOT NULL,
  request_reason		VARCHAR(45) NOT NULL,
  date_issued			DATETIME NOT NULL,
  authorizing_officer	VARCHAR(45) NOT NULL,
  or_no					INT NULL,
  amount_paid			FLOAT NOT NULL,
  id_status				ENUM('Active', 'Inactive', 'Lost') NOT NULL,
  resident_id			INT(5) NOT NULL,
  PRIMARY KEY			(resident_idcardno),
  INDEX					(resident_id ASC),
  INDEX					(or_no ASC),
  FOREIGN KEY			(resident_id)
    REFERENCES			resident(resident_id),
  FOREIGN KEY			(or_no)
    REFERENCES			receipt (or_no)
);

-- -----------------------------------------------------
-- Table mobile
-- -----------------------------------------------------
DROP TABLE IF EXISTS mobile;
CREATE TABLE IF NOT EXISTS mobile (
  mobile_no		BIGINT(10) NOT NULL,
  individual_id INT NOT NULL,
  PRIMARY KEY	(mobile_no),
  INDEX			(individual_id ASC),
  FOREIGN KEY	(individual_id)
    REFERENCES	individual(individual_id)
);

-- -----------------------------------------------------
-- Table vehicle
-- -----------------------------------------------------
DROP TABLE IF EXISTS vehicle;
CREATE TABLE IF NOT EXISTS vehicle (
  plate_no			VARCHAR(7) NOT NULL,
  owner_lastname	VARCHAR(45) NOT NULL,
  owner_firstname	VARCHAR(45) NOT NULL,
  owner_mi			VARCHAR(45) NOT NULL,
  resident_id		INT(5) NULL,
  vehicle_class		ENUM('P', 'C') NOT NULL,
  vehicle_type		ENUM('sedan', 'SUV', 'MPV/AUV', 'van', 'truck', 'motorcycle/scooter', 'others') NOT NULL,
  date_registered	DATETIME NOT NULL,
  reg_fee			DECIMAL NOT NULL,
  or_no				INT NOT NULL,
  PRIMARY KEY		(plate_no),
  INDEX				(resident_id ASC),
  INDEX				(or_no ASC),
  FOREIGN KEY		(resident_id)
    REFERENCES		resident(resident_id),
  FOREIGN KEY		(or_no)
    REFERENCES		receipt(or_no)
);

-- -----------------------------------------------------
-- Table orcr
-- -----------------------------------------------------
DROP TABLE IF EXISTS orcr;
CREATE TABLE IF NOT EXISTS orcr (
  orcr			VARCHAR(45) NOT NULL,
  plate_no		VARCHAR(7) NOT NULL,
  years_valid	VARCHAR(45) NOT NULL,
  orcr_file		INT NOT NULL,
  PRIMARY KEY	(orcr),
  INDEX			(plate_no ASC),
  INDEX			(orcr_file ASC),
  FOREIGN KEY	(plate_no)
    REFERENCES	vehicle(plate_no),
  FOREIGN KEY	(orcr_file)
    REFERENCES	hoa_files(file_id)
);

-- -----------------------------------------------------
-- Table sticker
-- -----------------------------------------------------
DROP TABLE IF EXISTS sticker;
CREATE TABLE IF NOT EXISTS sticker (
  sticker_id			INT NOT NULL,
  year_valid			INT(4) NOT NULL,
  plate_no				VARCHAR(7) NOT NULL,
  owner_type			ENUM('R', 'NR') NOT NULL,
  authorizing_officer	INT(5) NOT NULL,
  date_acquired			DATETIME NOT NULL,
  amount_paid			DECIMAL NOT NULL,
  or_no					INT NULL,
  PRIMARY KEY			(sticker_id),
  INDEX					(plate_no ASC),
  INDEX					(authorizing_officer ASC),
  INDEX					(or_no ASC),
  FOREIGN KEY			(plate_no)
    REFERENCES			vehicle(plate_no),
  FOREIGN KEY			(authorizing_officer)
    REFERENCES			hoa_officer(officer_id),
  FOREIGN KEY			(or_no)
    REFERENCES			receipt(or_no)
);

-- -----------------------------------------------------
-- Table hoaofficer_sched
-- -----------------------------------------------------
DROP TABLE IF EXISTS hoaofficer_sched;
CREATE TABLE IF NOT EXISTS hoaofficer_sched (
  officer_id	INT(5) NOT NULL,
  sched_time	ENUM('AM', 'PM') NOT NULL,
  avail_Mon		TINYINT(1) NULL,
  avail_Tue		TINYINT(1) NULL,
  avail_Wed		TINYINT(1) NULL,
  avail_Thu		TINYINT(1) NULL,
  avail_Fri		TINYINT(1) NULL,
  avail_Sat		TINYINT(1) NULL,
  avail_Sun		TINYINT(1) NULL,
  PRIMARY KEY	(officer_id, sched_time),
  INDEX			(officer_id ASC),
  FOREIGN KEY	(officer_id)
    REFERENCES	hoa_officer(officer_id)
);

-- -----------------------------------------------------
-- Table asset
-- -----------------------------------------------------
DROP TABLE IF EXISTS asset;
CREATE TABLE IF NOT EXISTS asset (
  asset_id			VARCHAR(10) NOT NULL,
  asset_name		VARCHAR(45) NOT NULL,
  description		VARCHAR(45) NOT NULL,
  date_acquired		DATE NOT NULL,
  for_rent			TINYINT(1) NOT NULL,
  asset_value		FLOAT NOT NULL,
  asset_type		ENUM('P', 'E', 'F', 'O') NOT NULL,
  asset_status		ENUM('W', 'DE', 'FR', 'FD', 'DI') NOT NULL,
  location			VARCHAR(45) NOT NULL,
  location_x		FLOAT NOT NULL,
  location_y		FLOAT NOT NULL,
  hoa_name			VARCHAR(45) NOT NULL,
  asset_container	VARCHAR(10) NULL,
  PRIMARY KEY		(asset_id),
  INDEX				(hoa_name ASC),
  INDEX				(asset_container ASC),
  FOREIGN KEY		(hoa_name)
    REFERENCES		hoa(hoa_name),
  FOREIGN KEY		(asset_container)
    REFERENCES		asset(asset_id)
);

-- -----------------------------------------------------
-- Table commercial_prop
-- -----------------------------------------------------
DROP TABLE IF EXISTS commercial_prop;
CREATE TABLE IF NOT EXISTS commercial_prop (
  property_code			VARCHAR(6) NOT NULL,
  commercial_type		ENUM('O', 'L', 'R', 'M') NOT NULL,
  commercial_maxten		INT NOT NULL,
  INDEX					(property_code ASC),
  PRIMARY KEY			(property_code),
  FOREIGN KEY			(property_code)
    REFERENCES			property(property_code)
);

-- -----------------------------------------------------
-- Table residential_prop
-- -----------------------------------------------------
DROP TABLE IF EXISTS residential_prop;
CREATE TABLE IF NOT EXISTS residential_prop (
  property_code VARCHAR(6) NOT NULL,
  household_id	INT(5) NOT NULL,
  INDEX			(property_code ASC),
  PRIMARY KEY	(property_code),
  INDEX			(household_id ASC),
  FOREIGN KEY	(property_code)
    REFERENCES	property(property_code),
  FOREIGN KEY	(household_id)
    REFERENCES	household(household_id)
);


-- -----------------------------------------------------
-- Add records to regions
-- -----------------------------------------------------
INSERT INTO	regions
	VALUES	('Region I'),
			('Region II'),
			('Region III'),
			('Region IV-A'),
            ('Region IV-B'),
            ('Region V'),
            ('Region VI'),
            ('Region VII'),
            ('Region VIII'),
            ('Region IX'),
            ('Region X'),
            ('Region XI'),
            ('Region XII'),
            ('Region XIII'),
            ('NCR'),
            ('CAR'),
            ('BARMM');

-- -----------------------------------------------------
-- Add records to provinces
-- -----------------------------------------------------
INSERT INTO	provinces
	VALUES	('Metro Manila','NCR'),
			('Bataan','Region III'),
			('Batangas','Region IV-A'),
			('Cavite','Region IV-A'),
            ('Laguna','Region IV-A');

-- -----------------------------------------------------
-- Add records to cities
-- -----------------------------------------------------
INSERT INTO	cities
	VALUES	('Manila','Metro Manila'),
			('Pasay','Metro Manila'),
			('Pasig','Metro Manila'),
			('Dasmarinas','Cavite'),
            ('Santa Rosa','Laguna');
            
-- -----------------------------------------------------
-- Add records to zipcodes
-- -----------------------------------------------------
INSERT INTO	zipcodes
	VALUES	('1001','680','Manila','Metro Manila'),
			('1002','780','Manila','Metro Manila'),
			('1003','880','Manila','Metro Manila');

-- -----------------------------------------------------
-- Add records to address
-- -----------------------------------------------------
INSERT INTO	address
	VALUES	(10000020, '24', 'De La Salle St.', '680', 'Manila', 'Metro Manila', 1001, 123.4567, 234.5678),
			(10000021, '45', 'De La Salle St.', '680', 'Manila', 'Metro Manila', 1001, 345.6789, 456.7890),
			(10000022, '77', 'Benilde St.', '680', 'Manila', 'Metro Manila', 1001, 567.8901, 678.9101),
            (10000023, '13', 'Mutien-Marie St.', '680', 'Manila', 'Metro Manila', 1001, 789.1011, 891.0111),
            (10000024, '50', 'Green Archer St.', '780', 'Manila', 'Metro Manila', 1002, 910.1112, 101.1121),
            (10000025, '11', 'Reims St.', '780', 'Manila', 'Metro Manila', 1002, 131.4151, 617.1819);

-- -----------------------------------------------------
-- Add records to hoa
-- -----------------------------------------------------
INSERT INTO	hoa
	VALUES	('Animo HOA', 10000020, 1911, 'www.animohoa.ph', 'Animo Green Homes', '15'),
			('Archer’s HOA', 10000024, 1999, 'www.archershoa.ph', 'Archer’s Residences', '10'),
			('Berde 1 HOA', 10000025, 2005, 'www.berdehoa.ph', 'Berde Subdivision 1', '20');

-- -----------------------------------------------------
-- Add records to individual
-- -----------------------------------------------------
INSERT INTO	individual
	VALUES	(2023202410, 'Dela Cruz', 'Juan', 'R', 'juandelacruz@gmail.com', '2000-01-05', 'M', 'jdlcruz', 'pic1.jpg', 'R'),
			(2023202411, 'Dela Cruz', 'Juanita', 'G', 'juanitadelacruz@gmail.com', '2002-10-10', 'F', 'juanitadlc', 'pic2.jpg', 'HR'),
			(2023202412, 'Rizal', 'Jose', 'P', 'joserizal@gmail.com', '1961-06-19', 'M', 'jprizal', 'pic3.jpg', 'HR'),
			(2023202413, 'Bonifacio', 'Andres', 'A', 'andresbonifacio@gmail.com', '1983-11-30', 'M', NULL, 'pic4.jpg', 'R'),
			(2023202414, 'Silang', 'Gabriela', 'R', 'gabrielasilang@gmail.com', '1991-03-19', 'F', 'grsilang', 'pic5.jpg', 'HR'),
			(2023202415, 'Luna', 'Juan', 'M', 'juanluna@gmail.com', '1991-03-19', 'M', 'jluna', 'pic5.jpg', 'H');

-- -----------------------------------------------------
-- Add records to homeowner
-- -----------------------------------------------------
INSERT INTO	homeowner
	VALUES	(30011, 5, 1, 1, 1, 10000021, NULL, NULL, 'Animo HOA', 2023202410),
			(30012, 12, 1, 1, 1, 10000022, NULL, NULL, 'Animo HOA', 2023202412),
			(30013, 10, 1, 1, 1, 10000023, NULL, NULL, 'Animo HOA', 2023202414),
            (30014, 6, 1, 1, 1, 10000024, NULL, NULL, 'Animo HOA', 2023202415);

-- -----------------------------------------------------
-- Add records to officer_positions
-- -----------------------------------------------------
INSERT INTO	officer_positions
	VALUES	('President'),
			('Vice-President'),
			('Secretary'),
			('Treasurer'),
			('Auditor');

-- -----------------------------------------------------
-- Add records to elections
-- -----------------------------------------------------
INSERT INTO	elections
	VALUES	('2022-1-12', 'Animo Clubhouse', 0, 'Aquino', 'Melchora', 'B',9172001434, 'Animo HOA'),
			('2022-11-19', 'Animo Clubhouse', 0, 'Del Pilar', 'Gregorio', 'A',9224657809, 'Animo HOA'),
			('2022-11-26', 'Animo Clubhouse', 1, 'Balagtas', 'Francisco', 'K',9224657809, 'Animo HOA');

-- -----------------------------------------------------
-- Add records to hoa_officer
-- -----------------------------------------------------
INSERT INTO	hoa_officer
	VALUES	(99901, 30012, 'President', '2023-01-09','2024-01-07','2022-11-26'),
			(99902, 30013, 'Secretary', '2023-01-09','2024-01-07','2022-11-26');

-- -----------------------------------------------------
-- Add records to hoa_files
-- -----------------------------------------------------
INSERT INTO	hoa_files
	VALUES	(555556661,'bylaws.pdf', 'notarized by-laws','D:/Animo HOA Documents/', 'pdf', '2020-03-17', 'Jose Rizal', 99901, 'Animo HOA'),
			(555556662,'ABC1234-ORCR2022.pdf', 'ABC1234 ORCR 2022','D:/Animo HOA Documents/Vehicle Registration/', 'pdf', '2022-05-06', 'Juan Dela Cruz', 99902, 'Animo HOA'),
            (555556663,'DEF6789-ORCR2022.pdf', 'DEF6789 ORCR 2022','D:/Animo HOA Documents/Vehicle Registration/', 'pdf', '2022-05-10', 'Emilio Aguinaldo', 99902, 'Animo HOA');

-- -----------------------------------------------------
-- Add records to property
-- -----------------------------------------------------
INSERT INTO	property
	VALUES	('B35L02', 300.00, '2018-02-15', 'R', 30011),
			('B11L08', 180.00, '2011-03-16', 'R', 30012),
            ('B42L09', 225.00, '2013-04-17', 'R', 30013),
            ('B25L10', 250.00, '2017-05-18', 'R', 30014),
            ('B39L13', 180.00, '2020-06-19', 'C', 30014);

-- -----------------------------------------------------
-- Add records to household
-- -----------------------------------------------------
INSERT INTO	household
	VALUES	(42001),
			(42002),
			(42003),
            (42004);

-- -----------------------------------------------------
-- Add records to resident
-- -----------------------------------------------------
INSERT INTO	resident
	VALUES	(40011, 0, 'husband', 1, 42001, 1, 2023202410),
			(40012, 0, 'homeowner', 1, 42001, 1, 2023202411),
            (40013, 0, 'homeowner', 1, 42002, 1, 2023202412),
            (40014, 1, 'none', 1, 42003, 0, 2023202413),
            (40015, 0, 'homeowner', 1, 42004, 1, 2023202414);

-- -----------------------------------------------------
-- Add records to receipt
-- -----------------------------------------------------
INSERT INTO	receipt
	VALUES	(202379991,'2023-07-20',1500.00),
			(202379992,'2023-08-25',2250.00),
            (202379993,'2023-09-01',830.00);

-- -----------------------------------------------------
-- Add records to resident_idcard
-- -----------------------------------------------------
INSERT INTO	resident_idcard
	VALUES	('ANIMO22001', '2022-01-30', 'New ID', '2022-02-04', 99902, NULL, 0.00, 'Active', 40013),
			('ANIMO22002', '2022-02-20-', 'New ID', '2022-02-04-', 99902, NULL, 0.00, 'Active', 40011),
            ('ANIMO22003', '2022-02-20', 'New ID', '2022-02-04', 99902, NULL, 0.00, 'Active', 40012);

-- -----------------------------------------------------
-- Add records to mobile
-- -----------------------------------------------------
INSERT INTO	mobile
	VALUES	(9175459870, 2023202410),
			(9173110229, 2023202411),
            (9207639255, 2023202412),
            (9226974142, 2023202413),
            (9181008621, 2023202414),
            (9224489773, 2023202415);

-- -----------------------------------------------------
-- Add records to vehicle
-- -----------------------------------------------------
INSERT INTO	vehicle
	VALUES	('ABC1234', 'Dela Cruz', 'Juan', 'R', 40011, 'P', 'SUV', '2023-07-20', 150.00, 202379991),
			('DEF6789', 'Aguinaldo', 'Emilio', 'N', NULL, 'C', 'truck', '2023-09-01', 500.00, 202379992);

-- -----------------------------------------------------
-- Add records to orcr
-- -----------------------------------------------------
INSERT INTO	orcr
	VALUES	('ORCR-109634885P', 'ABC1234', '2023-02-20 to 2024-02-19', 555556662),
			('ORCR-217459009C', 'DEF6789', '2023-06-25 to 2024-06-24', 555556663);

-- -----------------------------------------------------
-- Add records to sticker
-- -----------------------------------------------------
INSERT INTO	sticker
	VALUES	(202300100, 2023, 'ABC1234', 'R', 99902, '2023-07-20', 0.00, NULL),
			(202300600, 2023, 'DEF6789', 'NR', 99902, '2023-09-01', 1500.00, 202379992);

-- -----------------------------------------------------
-- Add records to hoaofficer_sched
-- -----------------------------------------------------
INSERT INTO	hoaofficer_sched
	VALUES	(99901, 'AM', 1, 1, 1, 1, 1, 1, 1),
			(99902, 'PM', 1, 1, 1, 1, 1, 1, 1);

-- -----------------------------------------------------
-- Add records to asset
-- -----------------------------------------------------
INSERT INTO	asset
	VALUES	('P000000001', 'Animo HOA Clubhouse', 'clubhouse', '1995-10-06', 1, 18000000.00, 'P', 'W', '24 De La Salle St.', 123.4567, 234.5678, 'Animo HOA', NULL),
			('E000000001', 'LED projector', 'projector', '2021-12-01', 1, 75000.00, 'E', 'W', '24 De La Salle St.', 123.4567, 234.5678, 'Animo HOA', 'P000000001'),
            ('P000000002', 'Animo HOA Basketball Court', 'basketball court', '1996-04-01', 1, 9000000.00, 'P', 'W', '01 Benilde St.', 543.2100, 765.4321, 'Animo HOA', NULL);

-- -----------------------------------------------------
-- Add records to commercial_prop
-- -----------------------------------------------------
INSERT INTO	commercial_prop
	VALUES	('B39L13','M',10);

-- -----------------------------------------------------
-- Add records to residential_prop
-- -----------------------------------------------------
INSERT INTO	residential_prop
	VALUES	('B35L02', 42001),
			('B11L08', 42002),
            ('B42l09', 42003),
            ('B25L10', 42004);
