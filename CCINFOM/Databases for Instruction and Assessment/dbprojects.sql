CREATE DATABASE  IF NOT EXISTS `dbprojects` /*!40100 DEFAULT CHARACTER SET utf8 */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `dbprojects`;
-- MySQL dump 10.13  Distrib 8.0.17, for Win64 (x86_64)
--
-- Host: localhost    Database: dbprojects
-- ------------------------------------------------------
-- Server version	8.0.17

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `department`
--

DROP TABLE IF EXISTS `department`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `department` (
  `DNAME` varchar(2) NOT NULL,
  `PHONE` decimal(7,0) DEFAULT NULL,
  PRIMARY KEY (`DNAME`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `department`
--

LOCK TABLES `department` WRITE;
/*!40000 ALTER TABLE `department` DISABLE KEYS */;
INSERT INTO `department` VALUES ('CT',5360276),('IT',5240402),('ST',5360277);
/*!40000 ALTER TABLE `department` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `employee`
--

DROP TABLE IF EXISTS `employee`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `employee` (
  `ENUM` decimal(4,0) NOT NULL,
  `NAME` varchar(50) DEFAULT NULL,
  `DOB` date DEFAULT NULL,
  `DNAME` varchar(2) DEFAULT NULL,
  PRIMARY KEY (`ENUM`),
  KEY `DNAME` (`DNAME`),
  CONSTRAINT `employee_ibfk_1` FOREIGN KEY (`DNAME`) REFERENCES `department` (`DNAME`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `employee`
--

LOCK TABLES `employee` WRITE;
/*!40000 ALTER TABLE `employee` DISABLE KEYS */;
INSERT INTO `employee` VALUES (8001,'Ko, Charibeth','1976-04-05','IT'),(8002,'Inventado, Paul','1980-03-02','IT'),(8003,'Chu, Allan','1983-08-11','ST'),(8004,'Cheng, Danny','1985-09-12','CT'),(8005,'Kampos, Karlo','1979-09-01','CT'),(8006,'Cu, Gregory','1980-05-05','CT'),(8007,'Cheng, Calvin','1975-05-04','ST'),(8008,'Chu, Shirley','1980-02-10','IT'),(8009,'Cu, Jiji','1982-11-12','ST');
/*!40000 ALTER TABLE `employee` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `employee_engineers`
--

DROP TABLE IF EXISTS `employee_engineers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `employee_engineers` (
  `ENUM` decimal(4,0) NOT NULL,
  `DEGREE` varchar(25) DEFAULT NULL,
  PRIMARY KEY (`ENUM`),
  CONSTRAINT `employee_engineers_ibfk_1` FOREIGN KEY (`ENUM`) REFERENCES `employee` (`ENUM`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `employee_engineers`
--

LOCK TABLES `employee_engineers` WRITE;
/*!40000 ALTER TABLE `employee_engineers` DISABLE KEYS */;
INSERT INTO `employee_engineers` VALUES (8001,'Electrical'),(8002,'Mechanical'),(8008,'Electronics');
/*!40000 ALTER TABLE `employee_engineers` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `employee_jobs`
--

DROP TABLE IF EXISTS `employee_jobs`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `employee_jobs` (
  `ENUM` decimal(4,0) NOT NULL,
  `JOBTITLE` varchar(2) NOT NULL,
  `DASSIGNED` date DEFAULT NULL,
  PRIMARY KEY (`JOBTITLE`,`ENUM`),
  KEY `ENUM` (`ENUM`),
  CONSTRAINT `employee_jobs_ibfk_1` FOREIGN KEY (`JOBTITLE`) REFERENCES `jobtitlelist` (`jcode`),
  CONSTRAINT `employee_jobs_ibfk_2` FOREIGN KEY (`ENUM`) REFERENCES `employee` (`ENUM`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `employee_jobs`
--

LOCK TABLES `employee_jobs` WRITE;
/*!40000 ALTER TABLE `employee_jobs` DISABLE KEYS */;
INSERT INTO `employee_jobs` VALUES (8001,'J1','2010-01-02'),(8002,'J1','2010-01-04'),(8008,'J1','2010-01-10'),(8001,'J2','2010-01-03'),(8003,'J4','2010-01-05'),(8004,'J5','2010-01-06'),(8009,'J5','2010-01-11'),(8006,'J6','2010-01-08'),(8007,'J6','2010-01-09'),(8005,'J7','2010-01-07');
/*!40000 ALTER TABLE `employee_jobs` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `employee_project`
--

DROP TABLE IF EXISTS `employee_project`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `employee_project` (
  `PNO` decimal(3,0) NOT NULL,
  `ENUM` decimal(4,0) NOT NULL,
  `DATEJOINED` date DEFAULT NULL,
  `DATELEFT` date DEFAULT NULL,
  PRIMARY KEY (`ENUM`,`PNO`),
  KEY `PNO` (`PNO`),
  CONSTRAINT `employee_project_ibfk_1` FOREIGN KEY (`ENUM`) REFERENCES `employee` (`ENUM`),
  CONSTRAINT `employee_project_ibfk_2` FOREIGN KEY (`PNO`) REFERENCES `project` (`pno`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `employee_project`
--

LOCK TABLES `employee_project` WRITE;
/*!40000 ALTER TABLE `employee_project` DISABLE KEYS */;
INSERT INTO `employee_project` VALUES (901,8001,'2010-02-01','2010-02-06'),(901,8002,'2010-02-02','2010-02-06'),(902,8002,'2010-02-05',NULL),(901,8004,'2010-02-03','2010-02-06'),(901,8005,'2010-02-04','2010-02-06'),(902,8005,'2010-02-06',NULL),(903,8006,'2010-02-09',NULL),(902,8007,'2010-02-08',NULL),(903,8007,'2010-02-10','2010-03-15'),(902,8008,'2010-02-07',NULL),(903,8009,'2010-02-11','2010-03-17');
/*!40000 ALTER TABLE `employee_project` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `employee_secretary`
--

DROP TABLE IF EXISTS `employee_secretary`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `employee_secretary` (
  `ENUM` decimal(4,0) NOT NULL,
  `TYPINGSPEED` decimal(3,0) DEFAULT NULL,
  PRIMARY KEY (`ENUM`),
  CONSTRAINT `employee_secretary_ibfk_1` FOREIGN KEY (`ENUM`) REFERENCES `employee` (`ENUM`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `employee_secretary`
--

LOCK TABLES `employee_secretary` WRITE;
/*!40000 ALTER TABLE `employee_secretary` DISABLE KEYS */;
INSERT INTO `employee_secretary` VALUES (8004,100),(8009,140);
/*!40000 ALTER TABLE `employee_secretary` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `employee_spouse`
--

DROP TABLE IF EXISTS `employee_spouse`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `employee_spouse` (
  `ENUM` decimal(4,0) NOT NULL,
  `DOM` date DEFAULT NULL,
  `SENUM` decimal(4,0) DEFAULT NULL,
  PRIMARY KEY (`ENUM`),
  KEY `SENUM` (`SENUM`),
  CONSTRAINT `employee_spouse_ibfk_1` FOREIGN KEY (`SENUM`) REFERENCES `employee` (`ENUM`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `employee_spouse`
--

LOCK TABLES `employee_spouse` WRITE;
/*!40000 ALTER TABLE `employee_spouse` DISABLE KEYS */;
INSERT INTO `employee_spouse` VALUES (8001,'2001-07-15',8007),(8003,'2004-08-23',8008),(8006,'2005-02-05',8009),(8007,'2001-07-15',8001),(8008,'2004-08-23',8003),(8009,'2005-02-05',8006);
/*!40000 ALTER TABLE `employee_spouse` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `jobtitlelist`
--

DROP TABLE IF EXISTS `jobtitlelist`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `jobtitlelist` (
  `JCODE` varchar(2) NOT NULL,
  `JOBDESC` varchar(25) DEFAULT NULL,
  PRIMARY KEY (`JCODE`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `jobtitlelist`
--

LOCK TABLES `jobtitlelist` WRITE;
/*!40000 ALTER TABLE `jobtitlelist` DISABLE KEYS */;
INSERT INTO `jobtitlelist` VALUES ('J1','Engineer'),('J2','Soul Breaker'),('J3','IT'),('J4','Foreman'),('J5','Secretary'),('J6','Crew'),('J7','Staff');
/*!40000 ALTER TABLE `jobtitlelist` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `orderdetails`
--

DROP TABLE IF EXISTS `orderdetails`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `orderdetails` (
  `ORDERCODE` varchar(3) NOT NULL,
  `EQUIPMENT` varchar(20) NOT NULL,
  PRIMARY KEY (`ORDERCODE`,`EQUIPMENT`),
  CONSTRAINT `orderdetails_ibfk_1` FOREIGN KEY (`ORDERCODE`) REFERENCES `orders` (`ordercode`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `orderdetails`
--

LOCK TABLES `orderdetails` WRITE;
/*!40000 ALTER TABLE `orderdetails` DISABLE KEYS */;
INSERT INTO `orderdetails` VALUES ('O01','TABLE'),('O02','CABINET'),('O02','CHAIR'),('O04','CABINET'),('O05','TABLE'),('O06','TABLE');
/*!40000 ALTER TABLE `orderdetails` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `orders`
--

DROP TABLE IF EXISTS `orders`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `orders` (
  `ORDERCODE` varchar(3) NOT NULL,
  `VCODE` varchar(4) DEFAULT NULL,
  `DNAME` varchar(2) DEFAULT NULL,
  `DATEPROC` date DEFAULT NULL,
  PRIMARY KEY (`ORDERCODE`),
  KEY `VCODE` (`VCODE`),
  KEY `DNAME` (`DNAME`),
  CONSTRAINT `orders_ibfk_1` FOREIGN KEY (`VCODE`) REFERENCES `vendor` (`vcode`),
  CONSTRAINT `orders_ibfk_2` FOREIGN KEY (`DNAME`) REFERENCES `department` (`DNAME`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `orders`
--

LOCK TABLES `orders` WRITE;
/*!40000 ALTER TABLE `orders` DISABLE KEYS */;
INSERT INTO `orders` VALUES ('O01','V001','IT','2010-02-01'),('O02','V002','ST','2010-02-02'),('O03','V003','CT','2010-02-03'),('O04','V004','ST','2010-02-04'),('O05','V005','IT','2010-02-05'),('O06','V005','ST','2010-02-06');
/*!40000 ALTER TABLE `orders` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `project`
--

DROP TABLE IF EXISTS `project`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `project` (
  `PNO` decimal(3,0) NOT NULL,
  `PNAME` varchar(30) DEFAULT NULL,
  `ESTCOST` decimal(9,2) DEFAULT NULL,
  `DEVSTAGE` varchar(15) DEFAULT NULL,
  PRIMARY KEY (`PNO`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `project`
--

LOCK TABLES `project` WRITE;
/*!40000 ALTER TABLE `project` DISABLE KEYS */;
INSERT INTO `project` VALUES (901,'Refinary',500000.00,'Planning'),(902,'PetroChem',1000000.00,'Execution'),(903,'Alternative Energy',1500000.00,'Planning');
/*!40000 ALTER TABLE `project` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `vendor`
--

DROP TABLE IF EXISTS `vendor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `vendor` (
  `VCODE` varchar(4) NOT NULL,
  `VNAME` varchar(30) DEFAULT NULL,
  `STREET` varchar(15) DEFAULT NULL,
  `ZIP` decimal(4,0) DEFAULT NULL,
  PRIMARY KEY (`VCODE`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `vendor`
--

LOCK TABLES `vendor` WRITE;
/*!40000 ALTER TABLE `vendor` DISABLE KEYS */;
INSERT INTO `vendor` VALUES ('V001','AA Enterprises','Taft',1300),('V002','BB Enterprises','Taft',1772),('V003','Global Supplies','P. Gil',1004),('V004','International Office','Quirino',1004),('V005','Computer Sales','National Road',1004),('V006','Computer Sales','Taft',1300);
/*!40000 ALTER TABLE `vendor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping events for database 'dbprojects'
--

--
-- Dumping routines for database 'dbprojects'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-11-23 12:22:03
