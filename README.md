# Your study assistant - Memorier
### COMP2012H Project H20
Deadline: Dec 4  
Click [Here](Proposal.md) to see our project proposal  
Click [Here](https://drive.google.com/file/d/1QqJLKz9xDS4XIAxSsNljEVxRXbxd51rZ/view?usp=sharing) to accsee the GUI Logic diagram  
Click [Here](doc/Report.md) to see our project report

## How to Compile and Run the Project
<font color=red size=4>**Very Important Section!**</font>
- You can directly use Qt to compile the code or using qmake and make.
- But for runing the program, since we are using MySQL database in the code, please make sure that you have built the QMYSQL plugin. **There is no integrated support for MySQL plugin in Qt**, you need to download and compile the source code yourself.
- If you want to would like to know how to compile the MySQL plugin, click [HERE](https://www.codenong.com/cs106162868/) for Linux and [HERE](https://blog.csdn.net/liang19890820/article/details/105071549) for Windows

## Current Progress
### 1. Basic Class Design
**Objective: Store, display, manage cards**
- [x] Base card class design 
- [x] Drived Classes design (4 in total)
- [x] Integrate the above with simple console interface
- [x] Network API encapsulating (done with Qt)
- [x] Linked List Template
- [x] Proficiency calculation method
- [x] MySQL API design // **Aborted!**

### 2. Qt Interface
**Objective: Qt Design, [Here](https://drive.google.com/file/d/1QqJLKz9xDS4XIAxSsNljEVxRXbxd51rZ/view?usp=sharing) is the GUI Design**
- [x] Welcome Page
- [x] Login and Sign Up page
- [x] Main Library page
- [x] Add cards
- [x] Review page
- [x] Testing page
- [x] Manage page

### 3. Optimization
**Optimization The Project**
- [x] Auto Login and password protection
- [x] Merge projects
- [x] More API to implement auxiliary functions (auto word select, auto translate...)
- [x] KMP algorithm for string matching
- [x] Two ways of reviewing and testing 
- [x] Filter in the review function
- [ ] Edit function in the managment

### 4. Report
**You can view the report [HERE](doc/Report.md)**  
- [x] Report OutLine
- [x] Part 1-2
- [ ] Part 3
- [ ] Part 4
- [x] Part 5-6


### 5. Future plan
**Yes, This Project Will Continue Even After the Project Period**
- [ ] Beautify the UI
- [ ] Add setting page 
- [ ] Port to Android platform
- [ ] Add label feature to classify cards
- [ ] Add uploading image function
