# Test report  

## Testing performed

> This section should describe your test plans, and results.  
Every test should have a clear goal so that pass/fail can be indicated against all tests actually performed.  
For some tests, it is a good idea to use screenshots of target and actual results.  
You should research testing to set your testing within the known methodologies.  

**User-experience tests and feedback**  
We asked people who were not familiar with the program to use it (with a short description of what the program supposed to do). Doing so allowed us to understand what changes we should do to make the interface more user-friendly. For example, up to some point while being in "smart device creator" mode, the new smart device was created over and over again when the user tried to move previously created smart device item. This required the user to delete the new items created by accident, which could be frustrating after some time. For that reason we implemented additional check 
to prevent creating new devices if the user clicks on area occupied by another device that was previously created (allowing to move it).  

**Tests to discover memory-management bugs**  
Multiple times during development it happened that the program crashed. Trying to find the reason of these crashes we set up the "Debug" configuration in Qt Designer which allowed to trace the functions called just before the program crashed. It also allowed to view the state of variables just before the crash. Examining these information allowed us to fix the crashes. In most situations the reason was lack of initialization of pointers to NULL in constructors or not recognizing that an object does not exist anymore (resulting in segmentation fault because of attempting to read/write illegal memory location).  

"Start debugging" button in Qt:  

![debug - start image](https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/debug%20-%20start.png?raw=true)  

Segmentation fault notification once the program crashes:  

![debug - segmentation fault image](https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/debug%20-%20segfault.png?raw=true)  

Debug interface in Qt following the crash:  

![debug - interface view image](https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/debug%20-%20view.png?raw=true)  

**Ad-hoc testing**  
Most of the tests performed during development were not formally written and involved:  
- making a change (e.g. adding some feature)  
- running the program and interacting with it trying to find out if the newly implemented feature works properly  
- spending additional minute or two considering if the newly implemented feature may potentially cause some bugs in unconventional circumstances (that are unlikely but possible to happen)  

**Automated tests**  
We did not implement any automatic testing like unit tests. In our opinion, ad-hoc testing was more time efficient and more appropriate because of our somewhat chaotic development pattern. At the begining of the project we had no idea how exactly we'll create the program, what features it will have, what will be the structure of it. In that case writing unit tests at early stage is either impossible or not worth the time because of great likelihood of the code changing later. In the later stages we focused on adding more features up till the last moment. Doing frequent ad-hoc tests and effectively using the debug mode allowed us to create stable program without using automated testing methods.  


**Non-functional testing**  
Just before the MVP deadline, we copied the program executable (along with the "resources" folder) to check if it will successfully run on a PC that does not have Qt installed. 
Thanks to that, we realized that 3 dynamically linked libraries ([Qt5Core.dll](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/blob/master/libs/Qt5Core.dll), 
[Qt5Gui.dll](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/blob/master/libs/Qt5Gui.dll), 
[Qt5Widgets.dll](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/blob/master/libs/Qt5Widgets.dll)) provided by Qt must be copied into the same directory because otherwise the program will not run.

Just before the final product report deadline we repeated the test and it turned out that the newly added functionality requires 2 more dynamically linked libraries ([Qt5Multimedia.dll](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/blob/master/libs/Qt5Multimedia.dll), [Qt5Network](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/blob/master/libs/Qt5Network.dll)). We included these in the [release.zip](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/blob/master/release.zip) package which contains all the files required to run the program.  


