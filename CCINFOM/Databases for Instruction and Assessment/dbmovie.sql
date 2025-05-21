CREATE DATABASE  IF NOT EXISTS `moviedb` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */;
USE `moviedb`;
-- MySQL dump 10.13  Distrib 5.7.17, for Win64 (x86_64)
--
-- Host: localhost    Database: moviedb
-- ------------------------------------------------------
-- Server version	8.0.11

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `actor`
--

DROP TABLE IF EXISTS `actor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `actor` (
  `act_id` int(11) NOT NULL,
  `act_fname` char(20) DEFAULT NULL,
  `act_lname` char(20) DEFAULT NULL,
  `act_gender` char(1) DEFAULT NULL,
  PRIMARY KEY (`act_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `actor`
--

LOCK TABLES `actor` WRITE;
/*!40000 ALTER TABLE `actor` DISABLE KEYS */;
INSERT INTO `actor` VALUES (101,'James','Stewart','M'),(102,'Deborah','Kerr','F'),(103,'Peter','OToole','M'),(104,'Robert','De Niro','M'),(105,'F. Murray','Abraham','M'),(106,'Harrison','Ford','M'),(107,'Nicole','Kidman','F'),(108,'Stephen','Baldwin','M'),(109,'Jack','Nicholson','M'),(110,'Mark','Wahlberg','M'),(111,'Woody','Allen','M'),(112,'Claire','Danes','F'),(113,'Tim','Robbins','M'),(114,'Kevin','Spacey','M'),(115,'Kate','Winslet','F'),(116,'Robin','Williams','M'),(117,'Jon','Voight','M'),(118,'Ewan','McGregor','M'),(119,'Christian','Bale','M'),(120,'Maggie','Gyllenhaal','F'),(121,'Dev','Patel','M'),(122,'Sigourney','Weaver','F'),(123,'David','Aston','M'),(124,'Ali','Astin','F');
/*!40000 ALTER TABLE `actor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `director`
--

DROP TABLE IF EXISTS `director`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `director` (
  `dir_id` int(11) NOT NULL,
  `dir_fname` char(20) DEFAULT NULL,
  `dir_lname` char(20) DEFAULT NULL,
  PRIMARY KEY (`dir_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `director`
--

LOCK TABLES `director` WRITE;
/*!40000 ALTER TABLE `director` DISABLE KEYS */;
INSERT INTO `director` VALUES (201,'Alfred','Hitchcock'),(202,'Jack','Clayton'),(203,'David','Lean'),(204,'Michael','Cimino'),(205,'Milos','Forman'),(206,'Ridley','Scott'),(207,'Stanley','Kubrick'),(208,'Bryan','Singer'),(209,'Roman','Polanski'),(210,'Paul','Thomas Anderson'),(211,'Woody','Allen'),(212,'Hayao','Miyazaki'),(213,'Frank','Darabont'),(214,'Sam','Mendes'),(215,'James','Cameron'),(216,'Gus','Van Sant'),(217,'John','Boorman'),(218,'Danny','Boyle'),(219,'Christopher','Nolan'),(220,'Richard','Kelly'),(221,'Kevin','Spacey'),(222,'Andrei','Tarkovsky'),(223,'Peter','Jackson');
/*!40000 ALTER TABLE `director` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `genres`
--

DROP TABLE IF EXISTS `genres`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `genres` (
  `gen_id` int(11) NOT NULL,
  `gen_title` char(20) DEFAULT NULL,
  PRIMARY KEY (`gen_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `genres`
--

LOCK TABLES `genres` WRITE;
/*!40000 ALTER TABLE `genres` DISABLE KEYS */;
INSERT INTO `genres` VALUES (1001,'Action'),(1002,'Adventure'),(1003,'Animation'),(1004,'Biography'),(1005,'Comedy'),(1006,'Crime'),(1007,'Drama'),(1008,'Horror'),(1009,'Music'),(1010,'Mystery'),(1011,'Romance'),(1012,'Thriller'),(1013,'War');
/*!40000 ALTER TABLE `genres` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `movie`
--

DROP TABLE IF EXISTS `movie`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `movie` (
  `mov_id` int(11) NOT NULL,
  `mov_title` char(50) DEFAULT NULL,
  `mov_year` int(11) DEFAULT NULL,
  `mov_time` int(11) DEFAULT NULL,
  `mov_lang` char(15) DEFAULT NULL,
  `mov_dt_rel` datetime DEFAULT NULL,
  `mov_rel_country` char(5) DEFAULT NULL,
  PRIMARY KEY (`mov_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `movie`
--

LOCK TABLES `movie` WRITE;
/*!40000 ALTER TABLE `movie` DISABLE KEYS */;
INSERT INTO `movie` VALUES (901,'Vertigo',1958,128,'English','1958-08-24 00:00:00','UK'),(902,'The Innocents',1961,100,'English','1962-02-19 00:00:00','SW'),(903,'Lawrence of Arabia',1962,216,'English','1962-12-11 00:00:00','UK'),(904,'The Deer Hunter',1978,183,'English','1979-03-08 00:00:00','UK'),(905,'Amadeus',1984,160,'English','1985-01-07 00:00:00','UK'),(906,'Blade Runner',1982,117,'English','1982-09-09 00:00:00','UK'),(907,'Eyes Wide Shut',1999,159,'English',NULL,'UK'),(908,'The Usual Suspects',1995,106,'English','1995-08-25 00:00:00','UK'),(909,'Chinatown',1974,130,'English','1974-08-09 00:00:00','UK'),(910,'Boogie Nights',1997,155,'English','1998-02-16 00:00:00','UK'),(911,'Annie Hall',1977,93,'English','1977-04-20 00:00:00','USA'),(912,'Princess Mononoke',1997,134,'Japanese','2001-10-19 00:00:00','UK'),(913,'The Shawshank Redemption',1994,142,'English','1995-02-17 00:00:00','UK'),(914,'American Beauty',1999,122,'English',NULL,'UK'),(915,'Titanic',1997,194,'English','1998-01-23 00:00:00','UK'),(916,'Good Will Hunting',1997,126,'English','1998-06-03 00:00:00','UK'),(917,'Deliverance',1972,109,'English','1982-10-05 00:00:00','UK'),(918,'Trainspotting',1996,94,'English','1996-02-23 00:00:00','UK'),(919,'The Prestige',2006,130,'English','2006-11-10 00:00:00','UK'),(920,'Donnie Darko',2001,113,'English',NULL,'UK'),(921,'Slumdog Millionaire',2008,120,'English','2009-01-09 00:00:00','UK'),(922,'Aliens',1986,137,'English','1986-08-29 00:00:00','UK'),(923,'Beyond the Sea',2004,118,'English','2004-11-26 00:00:00','UK'),(924,'Avatar',2009,162,'English','2009-12-17 00:00:00','UK'),(925,'Braveheart',1995,178,'English','1995-09-08 00:00:00','UK'),(926,'Seven Samurai',1954,207,'Japanese','1954-04-26 00:00:00','JP'),(927,'Spirited Away',2001,125,'Japanese','2003-09-12 00:00:00','UK'),(928,'Back to the Future',1985,116,'English','1985-12-04 00:00:00','UK');
/*!40000 ALTER TABLE `movie` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `movie_cast`
--

DROP TABLE IF EXISTS `movie_cast`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `movie_cast` (
  `act_id` int(11) NOT NULL,
  `mov_id` int(11) NOT NULL,
  `role` char(30) DEFAULT NULL,
  KEY `movie_cast_act_id_fkey` (`act_id`),
  KEY `movie_cast_mov_id_fkey` (`mov_id`),
  CONSTRAINT `movie_cast_act_id_fkey` FOREIGN KEY (`act_id`) REFERENCES `actor` (`act_id`),
  CONSTRAINT `movie_cast_mov_id_fkey` FOREIGN KEY (`mov_id`) REFERENCES `movie` (`mov_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `movie_cast`
--

LOCK TABLES `movie_cast` WRITE;
/*!40000 ALTER TABLE `movie_cast` DISABLE KEYS */;
INSERT INTO `movie_cast` VALUES (101,901,'John Scottie Ferguson'),(102,902,'Miss Giddens'),(103,903,'T.E. Lawrence'),(104,904,'Michael'),(105,905,'Antonio Salieri'),(106,906,'Rick Deckard'),(107,907,'Alice Harford'),(108,908,'McManus'),(110,910,'Eddie Adams'),(111,911,'Alvy Singer'),(112,912,'San'),(113,913,'Andy Dufresne'),(114,914,'Lester Burnham'),(115,915,'Rose DeWitt Bukater'),(116,916,'Sean Maguire'),(117,917,'Ed'),(118,918,'Renton'),(120,920,'Elizabeth Darko'),(121,921,'Older Jamal'),(122,922,'Ripley'),(114,923,'Bobby Darin'),(109,909,'J.J. Gittes'),(119,919,'Alfred Borden');
/*!40000 ALTER TABLE `movie_cast` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `movie_direction`
--

DROP TABLE IF EXISTS `movie_direction`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `movie_direction` (
  `dir_id` int(11) NOT NULL,
  `mov_id` int(11) NOT NULL,
  KEY `movie_direction_dir_id_fkey` (`dir_id`),
  KEY `movie_direction_mov_id_fkey` (`mov_id`),
  CONSTRAINT `movie_direction_dir_id_fkey` FOREIGN KEY (`dir_id`) REFERENCES `director` (`dir_id`),
  CONSTRAINT `movie_direction_mov_id_fkey` FOREIGN KEY (`mov_id`) REFERENCES `movie` (`mov_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `movie_direction`
--

LOCK TABLES `movie_direction` WRITE;
/*!40000 ALTER TABLE `movie_direction` DISABLE KEYS */;
INSERT INTO `movie_direction` VALUES (201,901),(202,902),(203,903),(204,904),(205,905),(206,906),(207,907),(208,908),(209,909),(210,910),(211,911),(212,912),(213,913),(214,914),(215,915),(216,916),(217,917),(218,918),(219,919),(220,920),(218,921),(215,922),(221,923);
/*!40000 ALTER TABLE `movie_direction` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `movie_genres`
--

DROP TABLE IF EXISTS `movie_genres`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `movie_genres` (
  `mov_id` int(11) NOT NULL,
  `gen_id` int(11) NOT NULL,
  KEY `movie_genres_gen_id_fkey` (`gen_id`),
  KEY `movie_genres_mov_id_fkey` (`mov_id`),
  CONSTRAINT `movie_genres_gen_id_fkey` FOREIGN KEY (`gen_id`) REFERENCES `genres` (`gen_id`),
  CONSTRAINT `movie_genres_mov_id_fkey` FOREIGN KEY (`mov_id`) REFERENCES `movie` (`mov_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `movie_genres`
--

LOCK TABLES `movie_genres` WRITE;
/*!40000 ALTER TABLE `movie_genres` DISABLE KEYS */;
INSERT INTO `movie_genres` VALUES (922,1001),(917,1002),(903,1002),(912,1003),(911,1005),(908,1006),(913,1006),(926,1007),(928,1007),(918,1007),(921,1007),(902,1008),(923,1009),(907,1010),(927,1010),(901,1010),(914,1011),(906,1012),(904,1013);
/*!40000 ALTER TABLE `movie_genres` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `rating`
--

DROP TABLE IF EXISTS `rating`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `rating` (
  `mov_id` int(11) NOT NULL,
  `rev_id` int(11) NOT NULL,
  `rev_stars` decimal(4,2) DEFAULT NULL,
  `num_o_ratings` int(11) DEFAULT NULL,
  KEY `rating_mov_id_fkey` (`mov_id`),
  KEY `rating_rev_id_fkey` (`rev_id`),
  CONSTRAINT `rating_mov_id_fkey` FOREIGN KEY (`mov_id`) REFERENCES `movie` (`mov_id`),
  CONSTRAINT `rating_rev_id_fkey` FOREIGN KEY (`rev_id`) REFERENCES `reviewer` (`rev_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `rating`
--

LOCK TABLES `rating` WRITE;
/*!40000 ALTER TABLE `rating` DISABLE KEYS */;
INSERT INTO `rating` VALUES (901,9001,8.40,263575),(902,9002,7.90,20207),(903,9003,8.30,202778),(906,9005,8.20,484746),(924,9006,7.30,NULL),(908,9007,8.60,779489),(909,9008,NULL,227235),(910,9009,3.00,195961),(911,9010,8.10,203875),(912,9011,8.40,NULL),(914,9013,7.00,862618),(915,9001,7.70,830095),(916,9014,4.00,642132),(925,9015,7.70,81328),(918,9016,NULL,580301),(920,9017,8.10,609451),(921,9018,8.00,667758),(922,9019,8.40,511613),(923,9020,6.70,13091);
/*!40000 ALTER TABLE `rating` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `reviewer`
--

DROP TABLE IF EXISTS `reviewer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `reviewer` (
  `rev_id` int(11) NOT NULL,
  `rev_name` char(30) DEFAULT NULL,
  PRIMARY KEY (`rev_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `reviewer`
--

LOCK TABLES `reviewer` WRITE;
/*!40000 ALTER TABLE `reviewer` DISABLE KEYS */;
INSERT INTO `reviewer` VALUES (9001,'Righty Sock'),(9002,'Jack Malvern'),(9003,'Flagrant Baronessa'),(9004,'Alec Shaw'),(9005,NULL),(9006,'Victor Woeltjen'),(9007,'Simon Wright'),(9008,'Neal Wruck'),(9009,'Paul Monks'),(9010,'Mike Salvati'),(9011,NULL),(9012,'Wesley S. Walker'),(9013,'Sasha Goldshtein'),(9014,'Josh Cates'),(9015,'Krug Stillo'),(9016,'Scott LeBrun'),(9017,'Hannah Steele'),(9018,'Vincent Cadena'),(9019,'Brandt Sponseller'),(9020,'Richard Adams');
/*!40000 ALTER TABLE `reviewer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping events for database 'moviedb'
--

--
-- Dumping routines for database 'moviedb'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-07-12 17:37:42
