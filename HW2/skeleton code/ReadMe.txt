**[[ About the Makefile ]]**  

Although the Makefile uses the line `CXX=clang++`, it seems that `clang++` is not installed in my system environment, so I replaced it with `CXX=g++` to use MinGW as the compiler instead.

Since the `rm` command doesn't work in the Windows environment, I replaced it with the `del` command.  

After opening CMD in the directory containing `main.cpp`, `manager.cpp`, and `device.cpp`, I confirmed that entering the `make` command generates only the executable file, without object files.

When I entered `.\main.exe` in the CMD window, I confirmed that the program ran successfully.

---


**[[ About the Source Code ]]**  

Other than deleting dynamically allocated objects, there were no specific instructions for additional functionality in the destructor of the Manager class, so no other features were added.

Although no specific instructions were given for handling the case where no object meets the deletion condition, support for this case was implemented.

Although no specific instructions were given for handling the case where main.cpp allocate more than 100 Device objects, support for this case was implemented.

As the opposite state of the Ring's "Enabled" was not specified, I assumed it to be "Disabled".  
Similarly, for the Earbud's "Yes" state, I assumed the opposite to be "No".

---


[[ Makefile 관련 ]]
Makefile의 "CXX=clang++" 구문을 사용하였으나,
제 컴퓨터 환경에서 clang++이 설치되어 있지 않은 것 같아 "CXX=g++"
구문을 대신 적어 컴파일러를 MinGW로 대체하였습니다.

윈도우 환경에서 rm 명령어가 작동하지 않아 del 명령어로 대체하였습니다.
이에, main.cpp, manager.cpp, device.cpp 파일이 있는 디렉토리에서 cmd를 연 후,
"make" 명령어 입력 시 오브젝트 파일 없이 실행파일만 생성됨을 확인하였습니다.

cmd 창에 ".\main.exe" 입력 시 프로그램이 정상적으로 작동함을 확인하였습니다.


[[ 소스코드 관련 ]]
Manager 객체의 desturctor에서 동적 할당된 객체들을 해제해주는 것 이외에 destructor에서 해야하는 일에 대한 지시가 없어, 따로 다른 기능들은 추가하지 않았습니다.

100개 초과의 device 객체를 할당하는 경우에 대한 예외 조항이 없으나, 구현하였습니다.

지우고자 하는 객체와 동일한 조건의 객체가 없는 경우에 대한 예외 조항이 없으나, 구현하였습니다.

Ring의 Enabled 상태의 반대 상황이 제시되어 있지 않아 Disabled라고 적었습니다.
(마찬가지로 Earbud의 Yes 상태의 반대말을 No로 적었습니다.)