-- MySQL dump 10.13  Distrib 5.7.19, for Linux (x86_64)
--
-- Host: localhost    Database: NORTHWIND
-- ------------------------------------------------------
-- Server version	5.7.19-0ubuntu0.16.04.1

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
-- Current Database: `NORTHWIND`
--

CREATE DATABASE /*IF NOT EXISTS*/ `NORTHWIND` /*!40100 DEFAULT CHARACTER SET latin1 */;

USE `NORTHWIND`;

--
-- Table structure for table `CUSTOMER`
--

DROP TABLE IF EXISTS `CUSTOMER`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `CUSTOMER` (
  `id` int(11) NOT NULL,
  `FirstName` varchar(40) NOT NULL,
  `LastName` varchar(40) DEFAULT NULL,
  `City` varchar(40) DEFAULT NULL,
  `Country` varchar(40) DEFAULT NULL,
  `Phone` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `CUSTOMER`
--

LOCK TABLES `CUSTOMER` WRITE;
/*!40000 ALTER TABLE `CUSTOMER` DISABLE KEYS */;
INSERT INTO `CUSTOMER` VALUES (0,'FirstName','LastName','City','Country','Phone'),(1,'Maria','Anders','Berlin','Germany','030-0074321'),(2,'Ana','Trujillo','MÃ©xico D.F.','Mexico','(5) 555-4729'),(3,'Antonio','Moreno','MÃ©xico D.F.','Mexico','(5) 555-3932'),(4,'Thomas','Hardy','London','UK','(171) 555-7788'),(5,'Christina','Berglund','LuleÃ¥','Sweden','0921-12 34 65'),(6,'Hanna','Moos','Mannheim','Germany','0621-08460'),(7,'FrÃ©dÃ©rique','Citeaux','Strasbourg','France','88.60.15.31'),(8,'MartÃ­n','Sommer','Madrid','Spain','(91) 555 22 82'),(9,'Laurence','Lebihan','Marseille','France','91.24.45.40'),(10,'Elizabeth','Lincoln','Tsawassen','Canada','(604) 555-4729'),(11,'Victoria','Ashworth','London','UK','(171) 555-1212'),(12,'Patricio','Simpson','Buenos Aires','Argentina','(1) 135-5555'),(13,'Francisco','Chang','MÃ©xico D.F.','Mexico','(5) 555-3392'),(14,'Yang','Wang','Bern','Switzerland','0452-076545'),(15,'Pedro','Afonso','Sao Paulo','Brazil','(11) 555-7647'),(16,'Elizabeth','Brown','London','UK','(171) 555-2282'),(17,'Sven','Ottlieb','Aachen','Germany','0241-039123'),(18,'Janine','Labrune','Nantes','France','40.67.88.88'),(19,'Ann','Devon','London','UK','(171) 555-0297'),(20,'Roland','Mendel','Graz','Austria','7675-3425'),(21,'Aria','Cruz','Sao Paulo','Brazil','(11) 555-9857'),(22,'Diego','Roel','Madrid','Spain','(91) 555 94 44'),(23,'Martine','RancÃ©','Lille','France','20.16.10.16'),(24,'Maria','Larsson','BrÃ¤cke','Sweden','0695-34 67 21'),(25,'Peter','Franken','MÃ¼nchen','Germany','089-0877310'),(26,'Carine','Schmitt','Nantes','France','40.32.21.21'),(27,'Paolo','Accorti','Torino','Italy','011-4988260'),(28,'Lino','Rodriguez','Lisboa','Portugal','(1) 354-2534'),(29,'Eduardo','Saavedra','Barcelona','Spain','(93) 203 4560'),(30,'JosÃ©','Pedro Freyre','Sevilla','Spain','(95) 555 82 82'),(31,'AndrÃ©','Fonseca','Campinas','Brazil','(11) 555-9482'),(32,'Howard','Snyder','Eugene','USA','(503) 555-7555'),(33,'Manuel','Pereira','Caracas','Venezuela','(2) 283-2951'),(34,'Mario','Pontes','Rio de Janeiro','Brazil','(21) 555-0091'),(35,'Carlos','HernÃ¡ndez','San CristÃ³bal','Venezuela','(5) 555-1340'),(36,'Yoshi','Latimer','Elgin','USA','(503) 555-6874'),(37,'Patricia','McKenna','Cork','Ireland','2967 542'),(38,'Helen','Bennett','Cowes','UK','(198) 555-8888'),(39,'Philip','Cramer','Brandenburg','Germany','0555-09876'),(40,'Daniel','Tonini','Versailles','France','30.59.84.10'),(41,'Annette','Roulet','Toulouse','France','61.77.61.10'),(42,'Yoshi','Tannamuri','Vancouver','Canada','(604) 555-3392'),(43,'John','Steel','Walla Walla','USA','(509) 555-7969'),(44,'Renate','Messner','Frankfurt a.M.','Germany','069-0245984'),(45,'Jaime','Yorres','San Francisco','USA','(415) 555-5938'),(46,'Carlos','GonzÃ¡lez','Barquisimeto','Venezuela','(9) 331-6954'),(47,'Felipe','Izquierdo','I. de Margarita','Venezuela','(8) 34-56-12'),(48,'Fran','Wilson','Portland','USA','(503) 555-9573'),(49,'Giovanni','Rovelli','Bergamo','Italy','035-640230'),(50,'Catherine','Dewey','Bruxelles','Belgium','(02) 201 24 67'),(51,'Jean','FresniÃ¨re','MontrÃ©al','Canada','(514) 555-8054'),(52,'Alexander','Feuer','Leipzig','Germany','0342-023176'),(53,'Simon','Crowther','London','UK','(171) 555-7733'),(54,'Yvonne','Moncada','Buenos Aires','Argentina','(1) 135-5333'),(55,'Rene','Phillips','Anchorage','USA','(907) 555-7584'),(56,'Henriette','Pfalzheim','KÃ¶ln','Germany','0221-0644327'),(57,'Marie','Bertrand','Paris','France','(1) 42.34.22.66'),(58,'Guillermo','FernÃ¡ndez','MÃ©xico D.F.','Mexico','(5) 552-3745'),(59,'Georg','Pipps','Salzburg','Austria','6562-9722'),(60,'Isabel','de Castro','Lisboa','Portugal','(1) 356-5634'),(61,'Bernardo','Batista','Rio de Janeiro','Brazil','(21) 555-4252'),(62,'LÃºcia','Carvalho','Sao Paulo','Brazil','(11) 555-1189'),(63,'Horst','Kloss','Cunewalde','Germany','0372-035188'),(64,'Sergio','GutiÃ©rrez','Buenos Aires','Argentina','(1) 123-5555'),(65,'Paula','Wilson','Albuquerque','USA','(505) 555-5939'),(66,'Maurizio','Moroni','Reggio Emilia','Italy','0522-556721'),(67,'Janete','Limeira','Rio de Janeiro','Brazil','(21) 555-3412'),(68,'Michael','Holz','GenÃ¨ve','Switzerland','0897-034214'),(69,'Alejandra','Camino','Madrid','Spain','(91) 745 6200'),(70,'Jonas','Bergulfsen','Stavern','Norway','07-98 92 35'),(71,'Jose','Pavarotti','Boise','USA','(208) 555-8097'),(72,'Hari','Kumar','London','UK','(171) 555-1717'),(73,'Jytte','Petersen','Kobenhavn','Denmark','31 12 34 56'),(74,'Dominique','Perrier','Paris','France','(1) 47.55.60.10'),(75,'Art','Braunschweiger','Lander','USA','(307) 555-4680'),(76,'Pascale','Cartrain','Charleroi','Belgium','(071) 23 67 22 20'),(77,'Liz','Nixon','Portland','USA','(503) 555-3612'),(78,'Liu','Wong','Butte','USA','(406) 555-5834'),(79,'Karin','Josephs','MÃ¼nster','Germany','0251-031259'),(80,'Miguel','Angel Paolino','MÃ©xico D.F.','Mexico','(5) 555-2933'),(81,'Anabela','Domingues','Sao Paulo','Brazil','(11) 555-2167'),(82,'Helvetius','Nagy','Kirkland','USA','(206) 555-8257'),(83,'Palle','Ibsen','Ã…rhus','Denmark','86 21 32 43'),(84,'Mary','Saveley','Lyon','France','78.32.54.86'),(85,'Paul','Henriot','Reims','France','26.47.15.10'),(86,'Rita','MÃ¼ller','Stuttgart','Germany','0711-020361'),(87,'Pirkko','Koskitalo','Oulu','Finland','981-443655'),(88,'Paula','Parente','Resende','Brazil','(14) 555-8122'),(89,'Karl','Jablonski','Seattle','USA','(206) 555-4112'),(90,'Matti','Karttunen','Helsinki','Finland','90-224 8858'),(91,'Zbyszek','Piestrzeniewicz','Warszawa','Poland','(26) 642-7012');
/*!40000 ALTER TABLE `CUSTOMER` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ORDERITEM`
--

DROP TABLE IF EXISTS `ORDERITEM`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ORDERITEM` (
  `id` int(11) NOT NULL,
  `OrderId` int(11) DEFAULT NULL,
  `Productid` int(11) DEFAULT NULL,
  `UnitPrice` decimal(12,0) DEFAULT '0',
  `Quantity` int(11) DEFAULT '1',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ORDERITEM`
--

LOCK TABLES `ORDERITEM` WRITE;
/*!40000 ALTER TABLE `ORDERITEM` DISABLE KEYS */;
INSERT INTO `ORDERITEM` VALUES (0,0,0,0,0),(1,1,11,14,12),(2,1,42,10,10),(3,1,72,35,5),(4,2,14,19,9),(5,2,51,42,40),(6,3,41,8,10),(7,3,51,42,35),(8,3,65,17,15),(9,4,22,17,6),(10,4,57,16,15),(11,4,65,17,20),(12,5,20,65,40),(13,5,33,2,25),(14,5,60,27,40),(15,6,31,10,20),(16,6,39,14,42),(17,6,49,16,40),(18,7,24,4,15),(19,7,55,19,21),(20,7,74,8,21),(21,8,2,15,20),(22,8,16,14,35),(23,8,36,15,25),(24,8,59,44,30),(25,9,53,26,15),(26,9,77,10,12),(27,10,27,35,25),(28,10,39,14,6),(29,10,77,10,15),(30,11,2,15,50),(31,11,5,17,65),(32,11,32,26,6),(33,12,21,8,10),(34,12,37,21,1),(35,13,41,8,16),(36,13,57,16,50),(37,13,62,39,15),(38,13,70,12,21),(39,14,21,8,20),(40,14,35,14,20),(41,15,5,17,12),(42,15,7,24,15),(43,15,56,30,2),(44,16,16,14,60),(45,16,24,4,28),(46,16,30,21,60),(47,16,74,8,36),(48,17,2,15,35),(49,17,41,8,25),(50,18,17,31,30),(51,18,70,12,20),(52,19,12,30,12),(53,20,40,15,50),(54,20,59,44,70),(55,20,76,14,15),(56,21,29,99,10),(57,21,72,28,4),(58,22,33,2,60),(59,22,72,28,20),(60,23,36,15,30),(61,23,43,37,25),(62,24,33,2,24),(63,25,20,65,6),(64,25,31,10,40),(65,25,72,28,24),(66,26,10,25,24),(67,26,31,10,15),(68,26,33,2,20),(69,26,40,15,60),(70,26,76,14,33),(71,27,71,17,20),(72,27,72,28,7),(73,28,24,4,12),(74,28,59,44,6),(75,29,10,25,15),(76,29,13,5,10),(77,30,28,36,20),(78,30,62,39,12),(79,31,44,16,16),(80,31,59,44,15),(81,31,63,35,8),(82,31,73,12,25),(83,32,17,31,15),(84,33,24,4,12),(85,33,55,19,20),(86,33,75,6,30),(87,34,19,7,1),(88,34,24,4,6),(89,34,35,14,4),(90,35,30,21,6),(91,35,57,16,2),(92,36,15,12,20),(93,36,19,7,18),(94,36,60,27,35),(95,36,72,28,3),(96,37,27,35,15),(97,37,44,16,21),(98,37,60,27,20),(99,37,67,11,5),(100,38,1,14,45),(101,38,40,15,40),(102,38,53,26,36),(103,39,35,14,100),(104,39,62,39,40),(105,40,16,14,40),(106,40,34,11,20),(107,40,46,10,15),(108,41,54,6,10),(109,41,68,10,3),(110,42,3,8,30),(111,42,64,27,9),(112,43,5,17,20),(113,43,29,99,15),(114,43,49,16,15),(115,43,77,10,10),(116,44,13,5,20),(117,44,44,16,24),(118,44,51,42,2),(119,45,20,65,20),(120,46,18,50,12),(121,46,24,4,10),(122,46,63,35,5),(123,46,75,6,6),(124,47,1,14,18),(125,47,17,31,15),(126,47,43,37,15),(127,47,60,27,21),(128,47,75,6,6),(129,48,56,30,4),(130,49,11,17,12),(131,49,16,14,30),(132,49,69,29,15),(133,50,39,14,60),(134,50,72,28,20),(135,51,2,15,40),(136,51,36,15,40),(137,51,59,44,30),(138,51,62,39,15),(139,52,19,7,15),(140,52,70,12,20),(141,53,66,14,30),(142,53,68,10,20),(143,54,40,15,10),(144,54,56,30,20),(145,55,17,31,40),(146,55,28,36,28),(147,55,43,37,12),(148,56,40,15,40),(149,56,65,17,30),(150,56,68,10,15),(151,57,49,16,30),(152,57,59,44,10),(153,57,71,17,2),(154,58,18,50,25),(155,58,29,99,25),(156,58,39,14,30),(157,59,30,21,10),(158,59,53,26,10),(159,59,54,6,5),(160,60,62,39,10),(161,60,68,10,3),(162,61,69,29,1),(163,61,70,12,5),(164,62,4,18,20),(165,62,6,20,30),(166,62,42,11,2),(167,62,43,37,20),(168,62,71,17,3),(169,63,16,14,10),(170,63,62,39,5),(171,64,42,11,6),(172,64,69,29,7),(173,65,28,36,4),(174,65,43,37,24),(175,65,53,26,20),(176,65,75,6,10),(177,66,36,15,12),(178,67,32,26,40),(179,67,58,11,30),(180,67,62,39,25),(181,68,34,11,14),(182,68,70,12,30),(183,69,41,8,10),(184,69,62,39,70),(185,70,1,14,20);
/*!40000 ALTER TABLE `ORDERITEM` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ORDERS`
--

DROP TABLE IF EXISTS `ORDERS`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ORDERS` (
  `id` int(11) NOT NULL,
  `OrderDate` datetime NOT NULL,
  `OrderNumber` varchar(10) DEFAULT NULL,
  `Customerid` int(11) DEFAULT NULL,
  `TotalAmount` int(11) DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ORDERS`
--

LOCK TABLES `ORDERS` WRITE;
/*!40000 ALTER TABLE `ORDERS` DISABLE KEYS */;
INSERT INTO `ORDERS` VALUES (0,'0000-00-00 00:00:00','OrderNumbe',0,0),(1,'2007-04-12 00:00:00','542378',85,440),(2,'2007-05-12 00:00:00','542379',79,1863),(3,'2007-08-12 00:00:00','542380',34,1813),(4,'2007-08-12 00:00:00','542381',84,671),(5,'2007-09-12 00:00:00','542382',76,3730),(6,'2007-10-12 00:00:00','542383',34,1445),(7,'2007-11-12 00:00:00','542384',14,625),(8,'2007-12-12 00:00:00','542385',68,2491),(9,'0000-00-00 00:00:00','542386',88,518),(10,'0000-00-00 00:00:00','542387',35,1120),(11,'0000-00-00 00:00:00','542388',20,2019),(12,'0000-00-00 00:00:00','542389',13,101),(13,'0000-00-00 00:00:00','542390',56,1746),(14,'0000-00-00 00:00:00','542391',61,448),(15,'0000-00-00 00:00:00','542392',65,625),(16,'0000-00-00 00:00:00','542393',20,2465),(17,'0000-00-00 00:00:00','542394',24,725),(18,'0000-00-00 00:00:00','542395',7,1176),(19,'0000-00-00 00:00:00','542396',87,365),(20,'0000-00-00 00:00:00','542397',25,4031),(21,'0000-00-00 00:00:00','542398',33,1101),(22,'0000-00-00 00:00:00','542399',89,676),(23,'2008-01-12 00:00:00','542400',87,1376),(24,'2008-01-12 00:00:00','542401',75,48),(25,'2008-02-12 00:00:00','542402',65,1456),(26,'2008-05-12 00:00:00','542403',63,2142),(27,'2008-06-12 00:00:00','542404',85,539),(28,'2008-07-12 00:00:00','542405',49,307),(29,'2008-08-12 00:00:00','542406',80,420),(30,'2008-09-12 00:00:00','542407',52,1201),(31,'2008-12-12 00:00:00','542408',5,1489),(32,'0000-00-00 00:00:00','542409',44,468),(33,'0000-00-00 00:00:00','542410',5,613),(34,'0000-00-00 00:00:00','542411',69,87),(35,'0000-00-00 00:00:00','542412',69,155),(36,'0000-00-00 00:00:00','542413',46,1415),(37,'0000-00-00 00:00:00','542414',44,1452),(38,'0000-00-00 00:00:00','542415',63,2179),(39,'0000-00-00 00:00:00','542416',63,3016),(40,'0000-00-00 00:00:00','542417',67,924),(41,'0000-00-00 00:00:00','542418',66,89),(42,'0000-00-00 00:00:00','542419',11,479),(43,'0000-00-00 00:00:00','542420',15,2169),(44,'0000-00-00 00:00:00','542421',61,553),(45,'0000-00-00 00:00:00','542422',81,1296),(46,'0000-00-00 00:00:00','542423',80,849),(47,'0000-00-00 00:00:00','542424',65,1888),(48,'2009-02-12 00:00:00','542425',85,122),(49,'2009-03-12 00:00:00','542426',46,1051),(50,'2009-04-12 00:00:00','542427',7,1420),(51,'2009-05-12 00:00:00','542428',37,3127),(52,'2009-06-12 00:00:00','542429',67,350),(53,'2009-09-12 00:00:00','542430',49,608),(54,'2009-09-12 00:00:00','542431',86,755),(55,'2009-10-12 00:00:00','542432',76,2709),(56,'2009-11-12 00:00:00','542433',30,1242),(57,'2009-12-12 00:00:00','542434',80,954),(58,'0000-00-00 00:00:00','542435',55,4157),(59,'0000-00-00 00:00:00','542436',69,499),(60,'0000-00-00 00:00:00','542437',48,424),(61,'0000-00-00 00:00:00','542438',2,89),(62,'0000-00-00 00:00:00','542439',37,1762),(63,'0000-00-00 00:00:00','542440',77,336),(64,'0000-00-00 00:00:00','542441',18,269),(65,'0000-00-00 00:00:00','542442',86,1615),(66,'0000-00-00 00:00:00','542443',63,182),(67,'0000-00-00 00:00:00','542444',65,2327),(68,'0000-00-00 00:00:00','542445',38,517),(69,'0000-00-00 00:00:00','542446',65,2835),(70,'0000-00-00 00:00:00','542447',48,288),(300,'2012-03-17 00:00:00','676',101,765);
/*!40000 ALTER TABLE `ORDERS` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `PRODUCT`
--

DROP TABLE IF EXISTS `PRODUCT`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `PRODUCT` (
  `id` int(11) NOT NULL,
  `ProductName` varchar(50) DEFAULT NULL,
  `Supplierid` int(11) DEFAULT NULL,
  `UnitPrice` decimal(12,0) DEFAULT '0',
  `Package` varchar(30) DEFAULT NULL,
  `IsDiscontinued` bit(1) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `PRODUCT`
--

LOCK TABLES `PRODUCT` WRITE;
/*!40000 ALTER TABLE `PRODUCT` DISABLE KEYS */;
INSERT INTO `PRODUCT` VALUES (0,'ProductName',0,0,'Package',''),(1,'Chai',1,18,'10 boxes x 20 bags',''),(2,'Chang',1,19,'24 - 12 oz bottles',''),(3,'Aniseed Syrup',1,10,'12 - 550 ml bottles',''),(4,'Chef Anton\'s Cajun Seasoning',2,22,'48 - 6 oz jars',''),(5,'Chef Anton\'s Gumbo Mix',2,21,'36 boxes',''),(6,'Grandma\'s Boysenberry Spread',3,25,'12 - 8 oz jars',''),(7,'Uncle Bob\'s Organic Dried Pears',3,30,'12 - 1 lb pkgs.',''),(8,'Northwoods Cranberry Sauce',3,40,'12 - 12 oz jars',''),(9,'Mishi Kobe Niku',4,97,'18 - 500 g pkgs.',''),(10,'Ikura',4,31,'12 - 200 ml jars',''),(11,'Queso Cabrales',5,21,'1 kg pkg.',''),(12,'Queso Manchego La Pastora',5,38,'10 - 500 g pkgs.',''),(13,'Konbu',6,6,'2 kg box',''),(14,'Tofu',6,23,'40 - 100 g pkgs.',''),(15,'Genen Shouyu',6,16,'24 - 250 ml bottles',''),(16,'Pavlova',7,17,'32 - 500 g boxes',''),(17,'Alice Mutton',7,39,'20 - 1 kg tins',''),(18,'Carnarvon Tigers',7,63,'16 kg pkg.',''),(19,'Teatime Chocolate Biscuits',8,9,'10 boxes x 12 pieces',''),(20,'Sir Rodney\'s Marmalade',8,81,'30 gift boxes',''),(21,'Sir Rodney\'s Scones',8,10,'24 pkgs. x 4 pieces',''),(22,'Gustaf\'s KnÃ¤ckebrÃ¶d',9,21,'24 - 500 g pkgs.',''),(23,'TunnbrÃ¶d',9,9,'12 - 250 g pkgs.',''),(24,'GuaranÃ¡ FantÃ¡stica',10,5,'12 - 355 ml cans',''),(25,'NuNuCa NuÃŸ-Nougat-Creme',11,14,'20 - 450 g glasses',''),(26,'GumbÃ¤r GummibÃ¤rchen',11,31,'100 - 250 g bags',''),(27,'Schoggi Schokolade',11,44,'100 - 100 g pieces',''),(28,'RÃ¶ssle Sauerkraut',12,46,'25 - 825 g cans',''),(29,'ThÃ¼ringer Rostbratwurst',12,124,'50 bags x 30 sausgs.',''),(30,'Nord-Ost Matjeshering',13,26,'10 - 200 g glasses',''),(31,'Gorgonzola Telino',14,13,'12 - 100 g pkgs',''),(32,'Mascarpone Fabioli',14,32,'24 - 200 g pkgs.',''),(33,'Geitost',15,3,'500 g',''),(34,'Sasquatch Ale',16,14,'24 - 12 oz bottles',''),(35,'Steeleye Stout',16,18,'24 - 12 oz bottles',''),(36,'Inlagd Sill',17,19,'24 - 250 g jars',''),(37,'Gravad lax',17,26,'12 - 500 g pkgs.',''),(38,'CÃ´te de Blaye',18,264,'12 - 75 cl bottles',''),(39,'Chartreuse verte',18,18,'750 cc per bottle',''),(40,'Boston Crab Meat',19,18,'24 - 4 oz tins',''),(41,'Jack\'s New England Clam Chowder',19,10,'12 - 12 oz cans',''),(42,'Singaporean Hokkien Fried Mee',20,14,'32 - 1 kg pkgs.',''),(43,'Ipoh Coffee',20,46,'16 - 500 g tins',''),(44,'Gula Malacca',20,19,'20 - 2 kg bags',''),(45,'Rogede sild',21,10,'1k pkg.',''),(46,'Spegesild',21,12,'4 - 450 g glasses',''),(47,'Zaanse koeken',22,10,'10 - 4 oz boxes',''),(48,'Chocolade',22,13,'10 pkgs.',''),(49,'Maxilaku',23,20,'24 - 50 g pkgs.',''),(50,'Valkoinen suklaa',23,16,'12 - 100 g bars',''),(51,'Manjimup Dried Apples',24,53,'50 - 300 g pkgs.',''),(52,'Filo Mix',24,7,'16 - 2 kg boxes',''),(53,'Perth Pasties',24,33,'48 pieces',''),(54,'TourtiÃ¨re',25,7,'16 pies',''),(55,'PÃ¢tÃ© chinois',25,24,'24 boxes x 2 pies',''),(56,'Gnocchi di nonna Alice',26,38,'24 - 250 g pkgs.',''),(57,'Ravioli Angelo',26,20,'24 - 250 g pkgs.',''),(58,'Escargots de Bourgogne',27,13,'24 pieces',''),(59,'Raclette Courdavault',28,55,'5 kg pkg.',''),(60,'Camembert Pierrot',28,34,'15 - 300 g rounds',''),(61,'Sirop d\'Ã©rable',29,29,'24 - 500 ml bottles',''),(62,'Tarte au sucre',29,49,'48 pies',''),(63,'Vegie-spread',7,44,'15 - 625 g jars',''),(64,'Wimmers gute SemmelknÃ¶del',12,33,'20 bags x 4 pieces',''),(65,'Louisiana Fiery Hot Pepper Sauce',2,21,'32 - 8 oz bottles',''),(66,'Louisiana Hot Spiced Okra',2,17,'24 - 8 oz jars',''),(67,'Laughing Lumberjack Lager',16,14,'24 - 12 oz bottles',''),(68,'Scottish Longbreads',8,13,'10 boxes x 8 pieces',''),(69,'Gudbrandsdalsost',15,36,'10 kg pkg.',''),(70,'Outback Lager',7,15,'24 - 355 ml bottles',''),(71,'Flotemysost',15,22,'10 - 500 g pkgs.',''),(72,'Mozzarella di Giovanni',14,35,'24 - 200 g pkgs.',''),(73,'RÃ¶d Kaviar',17,15,'24 - 150 g jars',''),(74,'Longlife Tofu',4,10,'5 kg pkg.',''),(75,'RhÃ¶nbrÃ¤u Klosterbier',12,8,'24 - 0.5 l bottles',''),(76,'LakkalikÃ¶Ã¶ri',23,18,'500 ml',''),(77,'Original Frankfurter grÃ¼ne SoÃŸe',12,13,'12 boxes',''),(78,'Stroopwafels',22,10,'24 pieces','');
/*!40000 ALTER TABLE `PRODUCT` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `SUPPLIER`
--

DROP TABLE IF EXISTS `SUPPLIER`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `SUPPLIER` (
  `id` int(11) NOT NULL,
  `CompanyName` varchar(40) DEFAULT NULL,
  `ContactTitle` varchar(40) DEFAULT NULL,
  `City` varchar(40) DEFAULT NULL,
  `Country` varchar(40) DEFAULT NULL,
  `Phone` varchar(30) DEFAULT NULL,
  `Fax` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `CompanyName` (`CompanyName`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `SUPPLIER`
--

LOCK TABLES `SUPPLIER` WRITE;
/*!40000 ALTER TABLE `SUPPLIER` DISABLE KEYS */;
INSERT INTO `SUPPLIER` VALUES (0,'CompanyName','ContactName','City','Country','Phone','Fax'),(1,'Exotic Liquids','Charlotte Cooper','London','UK','(171) 555-2222',''),(2,'New Orleans Cajun Delights','Shelley Burke','New Orleans','USA','(100) 555-4822',''),(3,'Grandma Kelly\'s Homestead','Regina Murphy','Ann Arbor','USA','(313) 555-5735','(313) 555-3349'),(4,'Tokyo Traders','Yoshi Nagase','Tokyo','Japan','(03) 3555-5011',''),(5,'Cooperativa de Quesos \'Las Cabras\'','Antonio del Valle Saavedra','Oviedo','Spain','(98) 598 76 54',''),(6,'Mayumi\'s','Mayumi Ohno','Osaka','Japan','(06) 431-7877',''),(7,'\"Pavlova',' Ltd.\"','Ian Devling','Melbourne','Australia','(03) 444-2343'),(8,'\"Specialty Biscuits',' Ltd.\"','Peter Wilson','Manchester','UK','(161) 555-4448'),(9,'PB KnÃ¤ckebrÃ¶d AB','Lars Peterson','GÃ¶teborg','Sweden','031-987 65 43','031-987 65 91'),(10,'Refrescos Americanas LTDA','Carlos Diaz','Sao Paulo','Brazil','(11) 555 4640',''),(11,'Heli SÃ¼ÃŸwaren GmbH & Co. KG','Petra Winkler','Berlin','Germany','(010) 9984510',''),(12,'Plutzer LebensmittelgroÃŸmÃ¤rkte AG','Martin Bein','Frankfurt','Germany','(069) 992755',''),(13,'Nord-Ost-Fisch Handelsgesellschaft mbH','Sven Petersen','Cuxhaven','Germany','(04721) 8713','(04721) 8714'),(14,'Formaggi Fortini s.r.l.','Elio Rossi','Ravenna','Italy','(0544) 60323','(0544) 60603'),(15,'Norske Meierier','Beate Vileid','Sandvika','Norway','(0)2-953010',''),(16,'Bigfoot Breweries','Cheryl Saylor','Bend','USA','(503) 555-9931',''),(17,'Svensk SjÃ¶fÃ¶da AB','Michael BjÃ¶rn','Stockholm','Sweden','08-123 45 67',''),(18,'Aux joyeux ecclÃ©siastiques','GuylÃ¨ne Nodier','Paris','France','(1) 03.83.00.68','(1) 03.83.00.62'),(19,'New England Seafood Cannery','Robb Merchant','Boston','USA','(617) 555-3267','(617) 555-3389'),(20,'Leka Trading','Chandra Leka','Singapore','Singapore','555-8787',''),(21,'Lyngbysild','Niels Petersen','Lyngby','Denmark','43844108','43844115'),(22,'Zaanse Snoepfabriek','Dirk Luchte','Zaandam','Netherlands','(12345) 1212','(12345) 1210'),(23,'Karkki Oy','Anne Heikkonen','Lappeenranta','Finland','(953) 10956',''),(24,'\"G\'day',' Mate\"','Wendy Mackenzie','Sydney','Australia','(02) 555-5914'),(25,'Ma Maison','Jean-Guy Lauzon','MontrÃ©al','Canada','(514) 555-9022',''),(26,'Pasta Buttini s.r.l.','Giovanni Giudici','Salerno','Italy','(089) 6547665','(089) 6547667'),(27,'Escargots Nouveaux','Marie Delamare','Montceau','France','85.57.00.07',''),(28,'Gai pÃ¢turage','Eliane Noz','Annecy','France','38.76.98.06','38.76.98.58'),(29,'ForÃªts d\'Ã©rables','Chantal Goulet','Ste-Hyacinthe','Canada','(514) 555-2955','(514) 555-2921');
/*!40000 ALTER TABLE `SUPPLIER` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2017-09-13  3:05:52
