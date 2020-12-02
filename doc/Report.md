# Memoeier Documentation and Report
### Group: H20 
### Author: ZHANG Zhong & ZHANG Jiekai

[toc]

---

## 0. Overview
### **Memorier is a learning aid for you, which can help you remember and review better.**  
You can store knowledge in the form of **adding memory cards**, and Memorier will arrange regular **review and test** functions for you.  
The review and test of the cards is according to the **forgetting curve** to strengthen your memory of knowledge. Also, we support **custom review and test**. You can select the **type you want** and the **time period** for the creation of the card to generate a review and test sequence.  
In addition, all your cards will be **automatically synchronized** on your cloud account, which is convenient for multi-device switching.

## 1. Compile and run the progeam
- You can directly use Qt to compile the code.
- But for runing the program, since we are using MySQL database in the code, please make sure that you have built the QMYSQL plugin. **There is no integrated support for MySQL plugin in Qt**, you need to download and compile the source code yourself.
- If you want to would like to know how to compile the MySQL plugin, click [HERE](https://www.codenong.com/cs106162868/) for Linux and [HERE](https://blog.csdn.net/liang19890820/article/details/105071549) for Windows

## 2. How to use Memorier
- Log in/Sign up your account (All your cards will be stored in cloud, so sign an account is a must)
- Add your card by cilck "**Add Card**" botton in the library page, there are 4 types of cards, we will explain each later.
- After adding the card you can "**Review**" them, either by their type or by the time you added it. (In the latter case, we will arrange the next review time according to the forgetting curve)
- The "**Test**" function is similar to review, but you need to answer the question in the card and we will record your score for future Review and Test
- In "**Management**" page you can delete or edit(later) your cards, there is a filter for searching cards.

## 3. Class structure and functions  
In the part we will go through all the important classes and functions used in our project.

### I. Card class and its drived classes

### II. Tool classes

### III. GUI(Qt) classes and GUI login

## 4. Brief description of program design

## 5. Future plan
Yes, This Project Will Continue Even After the Project Period
-  Beautify the UI and add cutscenes or more animation
-  Add image uploading function in cloud server
-  Add setting page (User can config their review time and rules)
-  Ported to mobile phone program, Optimize the touch screen user experience
-  Add label feature to classify cards, let users label their cards for easy sorting and review


