/*
 Navicat Premium Data Transfer

 Source Server         : ZJK
 Source Server Type    : MySQL
 Source Server Version : 80021
 Source Host           : laojk.club:3306
 Source Schema         : Memorier

 Target Server Type    : MySQL
 Target Server Version : 80021
 File Encoding         : 65001

 Date: 03/12/2020 20:36:26
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for card
-- ----------------------------
DROP TABLE IF EXISTS `card`;
CREATE TABLE `card`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `type` tinyint NOT NULL,
  `account` int NOT NULL,
  `title` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `review_times` int NOT NULL,
  `ac_time` int NOT NULL,
  `create_time` bigint NOT NULL,
  `last_review` bigint NOT NULL,
  `question` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `answer` varchar(1023) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `next_review` bigint NOT NULL DEFAULT 0,
  `next_test` bigint NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 5 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci COMMENT = 'Storing cards' ROW_FORMAT = Dynamic;

SET FOREIGN_KEY_CHECKS = 1;
