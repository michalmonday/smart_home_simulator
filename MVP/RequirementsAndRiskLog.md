# List of contents
* [Requirements](#requirements)
    * [Project Outline Requirements (quotations from assignment specification)](#project-outline-requirements-(quotations-from-assignment-specification))
        * [Functional](#functional)
        * [Non-Functional](#non-functional)
    * [Jira Functional User Story Issues](#jira-functional-user-story-issues)
    * [Jira Non-Functional User Story Issues](#jira-non-functional-user-story-issues)
* [Risk Log](#risk-log)
    * [Jira Risk Issues](#jira-risk-issues)

# Requirements
## Project Outline Requirements (quotations from assignment specification) 
### Functional
>1. The tool must allow for outline architectural designs to be either created within the tool or imported from an external source. These can be simple rectangular rooms with interconnecting doors and windows.
>2. Initially the tool needs to only support single storey apartment spaces.
>3. As a minimum a space can be a studio apartment consisting of one entrance door, a
lounge/kitchenette, toilet/bathroom and single bedroom. However, ideally the tool
should support more complex spaces (eg. one, two, three bedroom, en-suite, etc),
right up to bespoke multi-room executive apartments.
>4. As a minimum, the tool should model these spaces as a 2D top-down view.
>5. The designers should be able to position smart home devices within these
apartments (see below). This will be a ‘design’ mode.
>6. The designers should then be able to interact with these simulated devices to
explore the functionality available in the context of the architectural design (see
below). This will be a ‘simulator’ mode.  

### Non Functional
>1. The system must be PC based running on a standard office PC and monitor.
>2. The system can be developed in any programming language that is suitable to meet
the functional requirements. However, for the 2D implementation, it is
recommended to use Java (with AWT and/or SWING graphics libraries).
>3. The system should be suitable for non-technical users to use eg. designers
>4. The system should perform in real-time with no serious lags or delays in processing
>5. The design can make use of free third-party add-on software libraries if needed.

  
\
\
\
\
## Jira Functional User Story Issues
### 1. [As a regular user I want to navigate/scroll through canvas so that large designs can be made.](https://cseejira.essex.ac.uk/browse/CE292T1902-41)  
**Description:**  
This is an important feature that may negatively affect performance if implemented incorrectly. For example, if all of the grid lines will be drawn regardless of zoom/scroll, then it may slow down all the "for all graphic items" loops. Lack of ability to increase size of the drawing canvas, and lack of ability navigate through it, would limit the size of the designs and make user experience less comfortable.  

**Progress:**  
* [Implemented zoom feature by using snippet provided by Pavel Strakhov.](https://cseejira.essex.ac.uk/browse/CE292T1902-41?focusedWorklogId=26999&page=com.atlassian.jira.plugin.system.issuetabpanels%3Aworklog-tabpanel#worklog-26999)  
---> [Source of the snippet - "stackoverflow: QGraphicsView Zooming in and out under mouse position using mouse wheel"](https://stackoverflow.com/a/19114517/4620679)  
---> [Relavant gitlab commit - "Added zoom class by Pavel Strakhov (Ctrl+scroll to use)"](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/commit/4568c1a8f4c661ca1ea4829dfb8be2a2be4a4749)  
---> [Documentation of zoom feaure](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/blob/master/MVP/Demonstration.md#zoom)  

**Status:** Done.  

### 2. [As an engineer I want to import/export architectural designs using csv files so they can be used with other programs.](https://cseejira.essex.ac.uk/browse/CE292T1902-42)  
**Description:**  
The project outline document states that the program must be able to either enable the user to draw the architectural design himself or import it from external file. Drawing of the items is already available, so the additional ability to import/export is not essential (hence the low priority of this issue), however it would be a nice addition.  
**Progress:** None so far.  
**Status:** Not started.  

### 3. [As a regular user I want to press and drag LMB to draw basic shapes so positioning and sizing them is convenient.](https://cseejira.essex.ac.uk/browse/CE292T1902-43)  
**Description:**  
Press and drag functionality would allow the user to precisely specify 2 of the most important characteristics of each shape, which is size and position. It is probably much better solution than placing fixed-size shapes on LMB click, which would require additional resizing mechanism.   

**Progress:**  
* [Basic drawing](https://cseejira.essex.ac.uk/browse/CE292T1902-43?focusedWorklogId=27001&page=com.atlassian.jira.plugin.system.issuetabpanels%3Aworklog-tabpanel#worklog-27001)   
Implemented basic press and drag mode for rectangles/ellipses and uploaded example gif.  
---> [Example gif](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/commit/b58e3521e33d3e24a8d1724718f90094a944b11f)   
* ["Snap to grid"](https://cseejira.essex.ac.uk/browse/CE292T1902-43?focusedWorklogId=27002&page=com.atlassian.jira.plugin.system.issuetabpanels%3Aworklog-tabpanel#worklog-27002)   
Implemented "snap to grid" functionality when drawing shapes:   
---> [Gitlab commit](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/commit/a2543318f3cd330813d3ff9380cb3526ebd08990)  

**Status:** Done.  

### 4. [As a regular user I want to select and move multiple items at once so making changes to design is not mundane.](https://cseejira.essex.ac.uk/browse/CE292T1902-44)  
**Description:**  
It isn't really necessary but might be a nice addition, especially that it can be easily implemented in Qt which provides "QGraphicsItem" flags like "IsSelectable".   

**Progress:**  
Implemented it:  
---> [Documentation link](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/blob/master/MVP/Demonstration.md#select-move-and-delete-multiple-shapes)  

**Status:** Done.  

### 5. [As a regular user I want to be able to select the smallest item under the cursor so I don't have to move all the larger ones to reach obstructed items.](https://cseejira.essex.ac.uk/browse/CE292T1902-45)  
**Description:**  
When multiple items like rectangles, ellipses, polygons or smart device images are placed on top of each other, it may be troublesome to select the desired item. In order to allow easy selection of desired item, the smallest one should have priority. This would save a lot of frustration when moving items and improve overall user experience.  

**Progress:**   
* [Gitlab commit - On hover effect to show which element will be selected on click](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/commit/3dffcfdea97fd64160b18b86fbaa636fed056cec)  
* [Gitlab commit - Force high ZValue on smallest items when obstructed](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/commit/64eb47e61c81d251f3ff7a7a073ca3d6cf626ee4)    
---> [Documentation link](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/blob/master/MVP/Demonstration.md#detect-the-smallest-shape-under-cursor)    

**Status:** Done.  
  
\
\
\
\
## Jira Non Functional User Story Issues
### 1. [As a new user I want the program to notify me about how to control the program so I can use it without trial and error methodology.](https://cseejira.essex.ac.uk/browse/CE292T1902-40)  
**Description:**  
This could be accomplished by detecting the first launch of the program. For example, during the first launch of the program it could popup a window (QDialog), informing the user about controls or any useful tips about usage. Detection of the first launch could be implemented by storing boolean value in a simple text/ini file or a database.
Using database would allow to store more of user preferences as well as saving/loading designs.
More advanced approach would be to create "new user/tutorial" mode that would provide popups/instructions whenever some feature is used that wasn't used previously.  

**Progress:**  
* [**Created status bar**](https://cseejira.essex.ac.uk/browse/CE292T1902-40?focusedWorklogId=26998&page=com.atlassian.jira.plugin.system.issuetabpanels%3Aworklog-tabpanel#worklog-26998)  
Created status bar near the bottom of the main window which displays the current "creator" mode and the controls that can be used.  
---> [Relevant gitlab commit - "StatusBarMsg(msg) showing info to user..."](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/commit/b9fd2040092c4f77aef9d6f3a7d034c6923d3b33)  
---> [Documentation of the status bar](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/blob/master/MVP/Demonstration.md#status-info-bar)  

**Status:** In progress.  

### 2. [As a regular user I want the program to work using standard office PC and monitor to avoid additional investments or configuration](https://cseejira.essex.ac.uk/browse/CE292T1902-57)  
**Progress:**  
In the current state, the program works with any standard office PC running Windows. Installation is straightforward and involves copying ".exe" with "resources" folder onto target PC.    

**Status:** In progress.  

### 3. [As a regular user I want the program to work smoothly to avoid frustration](https://cseejira.essex.ac.uk/browse/CE292T1902-56)
**Description:**  
As mentioned in the Project Outline document, the program should work without lags or delays in processing.  

**Progress:**  
Performance is one of the aspects that is taken into account by us. This can be seen by looking at the [Performance issues due to Grid](performance-issues-due-to-grid) risk issue.  

**Status:** In progress.  

### 4. [As a developer I want to use free third-party libraries/frameworks to speed-up development](https://cseejira.essex.ac.uk/browse/CE292T1902-55)
**Description:**  
E.g. using Qt that provides a lot of in-built functionality to relatively easily create and manage graphical items (e.g. shapes, images) and GUI components (e.g. layouts, buttons, various widgets). Utilising ready to use libraries/frameworks allows to avoid implementing everything from scratch and focus on implementing desired features.  

**Progress:**  
The right choice was made regarding the suitable framework used in this project.  

**Status:** In progress.  

  
\
\
\
\
# Risk Log
## Jira Risk Issues
### 1. [Inability to work collaboratively](https://cseejira.essex.ac.uk/browse/CE292T1902-38)  
**Description:**  
Working together as a team is an important aspect of this module. Inability to do so is one of the risks that we should overcome in order to maximise efficiency of our work. This has several aspects to it:   
   - choosing programming language or framework that is suitable to team members
   - making sure that the chosen software is either available on campus PCs or that all team members own compatible hardware to use it
   - communication outside of the scheduled laboratories/lectures (as these are very limited)
   - co-operation and mutual support to overcome barriers that arise during development

**Mitigating attempts:**  
* [**Proceedings in the early stage**](https://cseejira.essex.ac.uk/browse/CE292T1902-38?focusedWorklogId=26744&page=com.atlassian.jira.plugin.system.issuetabpanels%3Aworklog-tabpanel#worklog-26744)  
For the first 2-3 weeks we discussed and considered which programming language to use for this project.
The most obvious option was to use Java, however there were multiple people trying to avoid using it. I suggested we could use python (pygame module) and showed "hello world" example found online that displayed a shape under the cursor. Everyone seemed to be happy with using python, however the final decision was set to be done later.
After further considerations and research online I realized that python/pygame lacks features/frameworks to easily design GUI components. Having some experience with Qt and C++ I suggested that we could use it because it has a designer tool which allows creating GUI elements in a convenient way. I created an example app which I showed to other team members. It was evident that using QT/C++ was acceptable choice by few members of the team, and not the 1st choice for other few members of the team.
Seeing the slight division in opinions I suggested that if we're going to use other language then I'd be happy to use it as long as an equivalent example of application is created using it. That is because I was sure that we can complete the project using Qt, and in case of choosing different language it would be good to know that the team members are also sure about completing it (using Java for example), because I wouldn't.
After some consideration the time came to decide and we chose to use Qt.  
---> [Relevant Jira issue (where we used comments to communicate)](https://cseejira.essex.ac.uk/browse/CE292T1902-1?focusedCommentId=24828&page=com.atlassian.jira.plugin.system.issuetabpanels%3Acomment-tabpanel#comment-24828)  
Commits with Qt app example and gifs/images showing its' functionality:  
---> [Added preview of QT_C++ app](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/commit/ee32faf8113823d83f5b9c9a33333971011b5fd8)  
---> [Added example of 'snap to grid' when drawing shapes](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/commit/a2543318f3cd330813d3ff9380cb3526ebd08990)  
---> [Added 'QT_C++ example 2.gif' (creating rect/ellipse)](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/commit/b58e3521e33d3e24a8d1724718f90094a944b11f)  
---> [Uploaded Qt example app source](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/commit/11805b4877e3c0e54882a86998f01dda905aedfe)  
 
* [**Solution for 1 of the aspects (Qt being installed on all PCs)**](https://cseejira.essex.ac.uk/browse/CE292T1902-38?focusedWorklogId=26745&page=com.atlassian.jira.plugin.system.issuetabpanels%3Aworklog-tabpanel#worklog-26745)  
Qt wasn't installed on campus PCs so we asked module tutor whether it would be possible to install it. After providing the [specification](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/raw/master/QT%20Folder/qt_setup.PNG) of currently used Qt version the same version of it was installed in CES Lab 2.
There was a small problem because the project would not compile, however creating a new project and copying source files fixed that problem and from that moment anyone can compile the app using Lab 2 PCs.  
* [**Creation of whatsapp group chat**](https://cseejira.essex.ac.uk/browse/CE292T1902-38?focusedWorklogId=26890&page=com.atlassian.jira.plugin.system.issuetabpanels%3Aworklog-tabpanel#worklog-26890)  
Invited all team members to the "ce292 Team 2" whatsapp group in order to improve the communication. Mostly because there's no chat on Jira (which requires to log in and manual check for any updates). Using whatsapp group allowed us to communicate easily and to some extent increase team cohesion.
* [**Invitation to get familiar with the code**](https://cseejira.essex.ac.uk/browse/CE292T1902-38?focusedWorklogId=26885&page=com.atlassian.jira.plugin.system.issuetabpanels%3Aworklog-tabpanel#worklog-26885)  
Invited everyone interested in contributing code to meet in laboratories (to talk about the current state of the program/code) using whatsapp group. Related issue:
https://cseejira.essex.ac.uk/browse/CE292T1902-15
* [**Shared ideas of features to add and arranged to meet and implement these together**](https://cseejira.essex.ac.uk/browse/CE292T1902-38?focusedWorklogId=27750&page=com.atlassian.jira.plugin.system.issuetabpanels%3Aworklog-tabpanel#worklog-27750)   
I [*Jarogniew] discussed with Michal about a few ideas, which have now been added as 'user stories'. 
We plan to work in these ideas together, hopefully we can get other team members involved.
The discussion went mainly in depth about the [Room Preset feature](https://cseejira.essex.ac.uk/browse/CE292T1902-52), but also included sharing thoughts about the following use case issues on Jira:  
---> [Recenter the screen with a button push.](https://cseejira.essex.ac.uk/browse/CE292T1902-50)  
---> [Display percentage of the gradient opacity (for smart light devices).](https://cseejira.essex.ac.uk/browse/CE292T1902-51)  
---> [Save a room and be able to paste multiple times, as well as in other projects.](https://cseejira.essex.ac.uk/browse/CE292T1902-52)  
---> [Line drawing feature.](https://cseejira.essex.ac.uk/browse/CE292T1902-53)  
---> [Re-scalable objects.](https://cseejira.essex.ac.uk/browse/CE292T1902-54)  


### 2. [Creating unclear "spaghetti" code that is hard to expand](https://cseejira.essex.ac.uk/browse/CE292T1902-37)  
**Description:**  
Writing relatively clean code is an important aspect of this project that will gain significance as the development progresses. Spending few minutes thinking to do something differently (instead of doing it straight away) may save long hours of hard work in the future. If this approach is not used then it may happen that we won't be able to create additional features because we will struggle to implement minimal requirements due to hard to solve bugs (caused by previously written, hard to expand code).

**Mitigating attempts:**  
* [**Documented attempts to mitigate the risk**](https://cseejira.essex.ac.uk/browse/CE292T1902-37?focusedWorklogId=26740&page=com.atlassian.jira.plugin.system.issuetabpanels%3Aworklog-tabpanel#worklog-26740)  
Several times during the development, effort was put into cleaning-up/refactoring the current code instead of adding new features to it. It has been documented on Jira:  
---> [Refactor/clean-up the code](https://cseejira.essex.ac.uk/browse/CE292T1902-14) - subtask of [Continue using QT](https://cseejira.essex.ac.uk/browse/CE292T1902-13) issue  
---> [Simplify QT code](https://cseejira.essex.ac.uk/browse/CE292T1902-28)  
...and it can be seen in the following commit logs:  
---> [Simplifying/refactoring update, not finished](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/commit/1d81b1e6eef1c0ccbf8f7a2907be2ffa11504227)  
---> [Finished refactoring, added icons for shapes and snap to grid while moving](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/commit/444769d2b2aae4347680192a14fd074017e9a07f)    
---> [Small cleanup](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/commit/e61db53843b3284cddf4dfb3d80252dadd9e1486)  
* [**Found and shared useful resources**](https://cseejira.essex.ac.uk/browse/CE292T1902-18)  
Found a great guide/book that precisely matches what will be needed for this project:    
---> [Guide link](https://www.packtpub.com/gb/game-development/game-programming-using-qt-5-beginners-guide-second-edition)   
---> [Book link](https://www.ebay.co.uk/itm/Game-Programming-using-Qt-5-Beginners-Guide-Create-amazing-gam-9781788399999/333193467470)   
The guide is free (requires free trial subscribtion on "packt" website that must be canceled within 10 days or it will take £9 from your account). I purchased the book, it should arrive within a week or 2 and hopefully will significantly improve the development of new features.   
Found great tutorial by "VoidRealms" (Bryan Cairns) about using QDialog which is exactly what Jarogniew suggested we could use to create separate window for the visual representation and UI of control screen smart device.   
---> [Tutorial link](https://www.youtube.com/watch?v=wUH_gu2HdQE)  
* [**Purchased a book about Qt programming**](https://cseejira.essex.ac.uk/browse/CE292T1902-37?focusedWorklogId=26845&page=com.atlassian.jira.plugin.system.issuetabpanels%3Aworklog-tabpanel#worklog-26845)  
Purchased a book called "Game programming using Qt 5". Hoping that it will help us to write the code "the right way" and avoid using over-complicated solutions. It was published in 2018 (so the risk of being outdated is very small) and written by the same person (Pavel Strakhov) who provided the [zooming snippet](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/commit/4568c1a8f4c661ca1ea4829dfb8be2a2be4a4749) we copied from [stackoverflow](https://stackoverflow.com/a/19114517/4620679).  
<img src="https://github.com/michalmonday/files/blob/master/ce292_team_project/images/MVP/book_pic_small.jpg?raw=true" alt="image_of_the_book" width=180 />

### 3. [Performance issues due to Grid](https://cseejira.essex.ac.uk/browse/CE292T1902-36)  
**Description:**  
As mentioned in the [Documentation.md](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/blob/master/MVP/Demonstration.md) file on gitlab, the current implementation of grid involves creating large number of "QGraphicsLineItem"s. There are several features of the program that require looping over all the items and the grid lines make all these loops less efficient.

**Mitigating attempts:**  
* [**Research of relevant resources**](https://cseejira.essex.ac.uk/browse/CE292T1902-36?focusedWorklogId=26739&page=com.atlassian.jira.plugin.system.issuetabpanels%3Aworklog-tabpanel#worklog-26739)  
Done some research about the topic of drawing grid using Qt and found few useful resources like:  
---> [qtcentre - Drawing grids efficiently in QGraphicsScene](https://www.qtcentre.org/threads/5609-Drawing-grids-efficiently-in-QGraphicsScene)  
---> [stackoverflow - Efficient Grid in Qt](https://stackoverflow.com/questions/12569578/efficient-grid-in-qt)  
---> [tufangorel, blogspot - Draw Grid on QGraphicsScene](http://tufangorel.blogspot.com/2011/08/draw-grid-on-qgraphicsscene.html)  

The next step will be to test the alternative methods, compare the performance and make a decision about potential change of currently used grid drawing method.

### 4. [Misdirected focus](https://cseejira.essex.ac.uk/browse/CE292T1902-39)
**Description:**  
Currently (21/11/19), it appears that from technical perspective our program is ahead of other teams. Despite that fact, there is a risk that our project will not be successful because we're not focusing on Jira enough. Addressing this risk and thinking of strategies to overcome it will allow us to keep being motivated on development of the program itself. That is because it would be very demotivating to get bad marks despite putting a lot of effort into the project in general.

**Mitigating attempts:**  
* [**Temporary stop with program development to focus on documentation and Jira**](https://cseejira.essex.ac.uk/browse/CE292T1902-39?focusedWorklogId=26794&page=com.atlassian.jira.plugin.system.issuetabpanels%3Aworklog-tabpanel#worklog-26794)  
Around 10 days before the MVP deadline we decided that it is a right time to stop working on additional features and focus on creating documentation, as well as taking care of Jira. The 4 "risk" issues (including this one) and the progressing documentation in gitlab's "MVP" directory are good examples of that.



