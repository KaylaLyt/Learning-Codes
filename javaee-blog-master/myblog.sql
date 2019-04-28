/*
Navicat MySQL Data Transfer

Source Server         : mysql
Source Server Version : 50096
Source Host           : localhost:3306
Source Database       : myblog

Target Server Type    : MYSQL
Target Server Version : 50096
File Encoding         : 65001

Date: 2018-11-20 17:28:35
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for t_article
-- ----------------------------
DROP TABLE IF EXISTS `t_article`;
CREATE TABLE `t_article` (
  `id` int(11) NOT NULL auto_increment,
  `title` varchar(80) NOT NULL,
  `author` varchar(30) NOT NULL,
  `sort` varchar(30) NOT NULL,
  `time` datetime default '2017-09-18 00:00:00',
  `star` int(11) default '0',
  `comment` int(11) default '0',
  `visit` int(11) default '0',
  `content` text,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of t_article
-- ----------------------------
INSERT INTO `t_article` VALUES ('10', '2333', '2333', '2333', '2018-11-20 17:08:46', '1', '0', '2', '哈哈哈哈哈');

-- ----------------------------
-- Table structure for t_article_delet
-- ----------------------------
DROP TABLE IF EXISTS `t_article_delet`;
CREATE TABLE `t_article_delet` (
  `id` int(11) NOT NULL auto_increment,
  `title` varchar(50) NOT NULL,
  `author` varchar(30) NOT NULL,
  `sort` varchar(30) NOT NULL,
  `time` datetime default '2017-09-18 00:00:00',
  `star` int(11) default '0',
  `comment` int(11) default '0',
  `visit` int(11) default '0',
  `content` text,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of t_article_delet
-- ----------------------------

-- ----------------------------
-- Table structure for t_comment
-- ----------------------------
DROP TABLE IF EXISTS `t_comment`;
CREATE TABLE `t_comment` (
  `id` int(11) NOT NULL auto_increment,
  `article_id` int(11) default NULL,
  `nickname` varchar(30) default NULL,
  `content` text,
  `time` datetime default '2017-09-18 00:00:00',
  `star` int(11) default '0',
  `diss` int(11) default '0',
  PRIMARY KEY  (`id`),
  KEY `article_id` (`article_id`),
  CONSTRAINT `article_id` FOREIGN KEY (`article_id`) REFERENCES `t_article` (`id`) ON DELETE CASCADE ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=19 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of t_comment
-- ----------------------------

-- ----------------------------
-- Table structure for t_tag
-- ----------------------------
DROP TABLE IF EXISTS `t_tag`;
CREATE TABLE `t_tag` (
  `id` int(11) default NULL,
  `tag` varchar(30) default NULL,
  KEY `id` (`id`),
  CONSTRAINT `t_tag_ibfk_1` FOREIGN KEY (`id`) REFERENCES `t_article` (`id`) ON DELETE CASCADE ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of t_tag
-- ----------------------------
INSERT INTO `t_tag` VALUES ('10', '2333');

-- ----------------------------
-- Table structure for t_user
-- ----------------------------
DROP TABLE IF EXISTS `t_user`;
CREATE TABLE `t_user` (
  `user_id` int(10) unsigned NOT NULL auto_increment COMMENT 'primary_key',
  `user_name` varchar(20) NOT NULL COMMENT 'username',
  `user_password` varchar(20) NOT NULL COMMENT 'password',
  PRIMARY KEY  (`user_id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of t_user
-- ----------------------------
INSERT INTO `t_user` VALUES ('1', '张三', '1234');

-- ----------------------------
-- Table structure for t_visitor
-- ----------------------------
DROP TABLE IF EXISTS `t_visitor`;
CREATE TABLE `t_visitor` (
  `id` int(11) NOT NULL auto_increment,
  `ip` varchar(50) default NULL,
  `time` varchar(50) default NULL,
  `web_ip` varchar(50) default NULL,
  `host` varchar(50) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=72 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of t_visitor
-- ----------------------------
INSERT INTO `t_visitor` VALUES ('52', '0:0:0:0:0:0:0:1', '2018-11-20 17:08:31', '0:0:0:0:0:0:0:1', '0:0:0:0:0:0:0:1');
INSERT INTO `t_visitor` VALUES ('53', '0:0:0:0:0:0:0:1', '2018-11-20 17:09:15', '0:0:0:0:0:0:0:1', '0:0:0:0:0:0:0:1');
INSERT INTO `t_visitor` VALUES ('54', '0:0:0:0:0:0:0:1', '2018-11-20 17:11:06', '0:0:0:0:0:0:0:1', '0:0:0:0:0:0:0:1');
INSERT INTO `t_visitor` VALUES ('55', '0:0:0:0:0:0:0:1', '2018-11-20 17:12:11', '0:0:0:0:0:0:0:1', '0:0:0:0:0:0:0:1');
INSERT INTO `t_visitor` VALUES ('56', '0:0:0:0:0:0:0:1', '2018-11-20 17:15:41', '0:0:0:0:0:0:0:1', '0:0:0:0:0:0:0:1');
INSERT INTO `t_visitor` VALUES ('57', '0:0:0:0:0:0:0:1', '2018-11-20 17:17:28', '0:0:0:0:0:0:0:1', '0:0:0:0:0:0:0:1');
INSERT INTO `t_visitor` VALUES ('58', '0:0:0:0:0:0:0:1', '2018-11-20 17:17:28', '0:0:0:0:0:0:0:1', '0:0:0:0:0:0:0:1');
INSERT INTO `t_visitor` VALUES ('59', '0:0:0:0:0:0:0:1', '2018-11-20 17:17:29', '0:0:0:0:0:0:0:1', '0:0:0:0:0:0:0:1');
INSERT INTO `t_visitor` VALUES ('60', '0:0:0:0:0:0:0:1', '2018-11-20 17:17:41', '0:0:0:0:0:0:0:1', '0:0:0:0:0:0:0:1');
INSERT INTO `t_visitor` VALUES ('61', '0:0:0:0:0:0:0:1', '2018-11-20 17:20:31', '0:0:0:0:0:0:0:1', '0:0:0:0:0:0:0:1');
INSERT INTO `t_visitor` VALUES ('62', '0:0:0:0:0:0:0:1', '2018-11-20 17:20:31', '0:0:0:0:0:0:0:1', '0:0:0:0:0:0:0:1');
INSERT INTO `t_visitor` VALUES ('63', '0:0:0:0:0:0:0:1', '2018-11-20 17:20:32', '0:0:0:0:0:0:0:1', '0:0:0:0:0:0:0:1');
INSERT INTO `t_visitor` VALUES ('64', '0:0:0:0:0:0:0:1', '2018-11-20 17:20:59', '0:0:0:0:0:0:0:1', '0:0:0:0:0:0:0:1');
INSERT INTO `t_visitor` VALUES ('65', '0:0:0:0:0:0:0:1', '2018-11-20 17:22:08', '0:0:0:0:0:0:0:1', '0:0:0:0:0:0:0:1');
INSERT INTO `t_visitor` VALUES ('66', '0:0:0:0:0:0:0:1', '2018-11-20 17:22:08', '0:0:0:0:0:0:0:1', '0:0:0:0:0:0:0:1');
INSERT INTO `t_visitor` VALUES ('67', '0:0:0:0:0:0:0:1', '2018-11-20 17:23:07', '0:0:0:0:0:0:0:1', '0:0:0:0:0:0:0:1');
INSERT INTO `t_visitor` VALUES ('68', '0:0:0:0:0:0:0:1', '2018-11-20 17:25:19', '0:0:0:0:0:0:0:1', '0:0:0:0:0:0:0:1');
INSERT INTO `t_visitor` VALUES ('69', '0:0:0:0:0:0:0:1', '2018-11-20 17:25:52', '0:0:0:0:0:0:0:1', '0:0:0:0:0:0:0:1');
INSERT INTO `t_visitor` VALUES ('70', '0:0:0:0:0:0:0:1', '2018-11-20 17:26:14', '0:0:0:0:0:0:0:1', '0:0:0:0:0:0:0:1');
INSERT INTO `t_visitor` VALUES ('71', '0:0:0:0:0:0:0:1', '2018-11-20 17:26:59', '0:0:0:0:0:0:0:1', '0:0:0:0:0:0:0:1');
