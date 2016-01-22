-- phpMyAdmin SQL Dump
-- version 4.4.14
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Oct 25, 2015 at 03:42 PM
-- Server version: 5.6.26
-- PHP Version: 5.5.28

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `MP1`
--

-- --------------------------------------------------------

--
-- Table structure for table `Monsters`
--

CREATE TABLE IF NOT EXISTS `Monsters` (
  `id` int(11) NOT NULL DEFAULT '0',
  `name` varchar(32) DEFAULT NULL,
  `STR` int(11) DEFAULT NULL,
  `VIT` int(11) DEFAULT NULL,
  `DEX` int(11) DEFAULT NULL,
  `AGI` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `Monsters`
--

INSERT INTO `Monsters` (`id`, `name`, `STR`, `VIT`, `DEX`, `AGI`) VALUES
(0, 'Shadow', 1, 1, 1, 1),
(1, '3DShadow', 1, 1, 1, 1),
(2, '3DGigas', 3, 2, 1, 1),
(3, '3DSoldier', 2, 1, 2, 1),
(4, 'Bomb', 2, 1, 2, 1),
(5, 'Cactuar', 5, 1, 2, 3);

-- --------------------------------------------------------

--
-- Table structure for table `Saves`
--

CREATE TABLE IF NOT EXISTS `Saves` (
  `slot` int(11) NOT NULL DEFAULT '0',
  `soriku` varchar(32) DEFAULT NULL,
  `name` varchar(32) DEFAULT NULL,
  `level` int(11) DEFAULT NULL,
  `hp` int(11) DEFAULT NULL,
  `mp` int(11) DEFAULT NULL,
  `x` int(11) DEFAULT NULL,
  `y` int(11) DEFAULT NULL,
  `STR` int(11) DEFAULT NULL,
  `MAG` int(11) DEFAULT NULL,
  `VIT` int(11) DEFAULT NULL,
  `DEX` int(11) DEFAULT NULL,
  `AGI` int(11) DEFAULT NULL,
  `experience` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `Saves`
--

INSERT INTO `Saves` (`slot`, `soriku`, `name`, `level`, `hp`, `mp`, `x`, `y`, `STR`, `MAG`, `VIT`, `DEX`, `AGI`, `experience`) VALUES
(1, 'sora', 'Sora', 25, 100, 100, 3, 2, 50, 50, 50, 50, 50, 15),
(2, 'sora', 'Dale', 2, 22, 8, 4, 6, 5, 1, 4, 3, 5, 6),
(3, 'sora', 'Sora', 5, 13, 15, 3, 3, 9, 7, 7, 5, 5, 15);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `Monsters`
--
ALTER TABLE `Monsters`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `Saves`
--
ALTER TABLE `Saves`
  ADD PRIMARY KEY (`slot`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
