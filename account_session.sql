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

 Date: 03/12/2020 20:36:18
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for account_session
-- ----------------------------
DROP TABLE IF EXISTS `account_session`;
CREATE TABLE `account_session`  (
  `id` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `account_id` int NOT NULL,
  `expire_at` bigint NOT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

SET FOREIGN_KEY_CHECKS = 1;
