# ft_server 개념

### 가상화

- 물리적인 하드웨어 장치를 논리적인 객체로 추상화 하는 것

- 하나의 자원을 쪼개서 쓰거나, 여러개의 자원을 하나인것 처럼 묶어서 쓸 수 있도록 해준다


### VM(Virtual machine)

- 하나의 컴퓨터 위에 하나의 OS만 있는 것을 효율화하고자 가상화층을 만들고 그 위에 OS를 새로 설치하는 기법

- 내 컴퓨터는 윈도우인데 리눅스도 쓰고 싶다면 가상머신을 쓸 수 있다

- 작동원리 

    - 하이퍼바이저라는 소프트웨어가 물리 리소스를 분할하여 이 리소스를 필요로 하는 VM이 사용할 수 있도록 한다
    

### 하이퍼바이저 

- 호스트 시스템에서 다수의 게스트 OS를 구동할 수 있게 하는 소프트웨어

- 하드웨어를 가상화하면서 하드웨어와 각각의 VM을 모니터링하는 중간 관리자

- 네이티브 or 하이퍼바이저형, Monolithic

    <p>
        <img width="156" alt="스크린샷 2021-03-28 오후 5 25 45" src="https://user-images.githubusercontent.com/48857296/112746589-af3c0e80-8fea-11eb-9c8b-b4daec4764e1.png">
    </p>

    - OS가 없고 비교적 가볍게 만들어져 하드웨어 성능을 그대로 게스트 OS에 반영
    
    - 하이퍼바이저가 하드웨어 바로 위에서 실행되는 방식
    
    - 하이퍼바이저가 하드웨어를 직접 제어하기 때문에 자원을 효율적으로 사용할 수 있고, 별도의 호스트 OS가 없으므로 오버헤드가 적지만 여러 하드웨어 드라이버를 세팅해야 하므로 설치가 어렵다

- 호트스형, Microkernel

    <p>
        <img width="240" alt="스크린샷 2021-03-28 오후 5 26 39" src="https://user-images.githubusercontent.com/48857296/112746609-ced33700-8fea-11eb-88ea-71672c9ac6aa.png">
    </p>
    
    - 일반적인 소프트웨어처럼 호스트 OS위에 실행된다
    
    - 하드웨어 자원을 VM 내부의 게스트 OS에 에뮬레이트 하는 방식
    
    - 각 하드웨어에 마이크로커널형 하이퍼바이저를 설치할 때마다 관리 OS가 설치되고 그 위에서 게스트 OS가 가동되는 모델, 리소스가 미리 소비된다
    
    - 각 게스트 OS를 가동시킬 때 관리 OS측 처리를 기다려야 하기 때문에 하드웨어 리소스를 게스트 OS에서만 소비하기 어려움
    
### Container

- 리눅스 기반 시스템에서 프로세스 간 격리를 위해 사용하던 기술들을 조합하여 발전시킨 것

- chroot와 네임 스페이스, cgroup을 조합한 LXC에서부터 컨테이너 가상화 기술이 발전

    - chroot
        
        - 특정 디렉토리를 루트로 인식하게끔 하는 명령어
        
    - 네임 스페이스
    
        - 리눅스 시스템 자원을 묶어 프로세스에 할당하는 방식으로, 하나의 프로세스 자원을 관리하는 기능
        
    - cgroup
    
        - CPU, 메모리 등 프로세스 그룹의 시스템 자원 사용량을 관리하며 특정 어플리케이션이 자원을 과다하게 사용하는 것을 제한
        
- 이처럼 격리된 고유 영역에서 할당된 자원을 이용해 어플리케이션을 실행하는 것을 의미하는 컨테이너는 어플리케이션의 필요한 라이브러리와 바이너리, 기타 구성 파일을 '이미지' 단위로 빌드하여 패키지로 배포한다

- 실행에 필요한 모든 환경이 준비되어 있으므로 어떤 환경에서도 어플리케이션을 오류 없이 동작시킬 수 있다
    
### VM vs 컨테이너

- 컨테이너

    - 컨테이너는 하이퍼바이저와 게스트 OS가 필요하지 않으므로 더 가볍다
    
    - 서비스 시작 시간도 짧고 크기가 작아 컨테이너 복제와 배포에 용이
    
    - 어플리케이션을 실행할 때에도 물리 서버에서 어플리케이션 하나를 실행하는 것과 마찬가지로, 호스트 OS 위에 어플리케이션의 실행 패키지인 '이미지'를 배포하기만 하면 된다
    
- VM

    -VM은 항상 게스트 OS가 포함되므로 크고, 어플리케이션을 실행할 때에도 먼저 VM을 띄우고 자원을 할당한 다음, 게스트 OS를 부팅하여 어플리케이션을 실행시켜야 한다
    

### Docker

- Linux 컨테이너를 만들고 사용할 수 있도록 하는 컨테이너화 기술
    
- Linux 커널과 함께 Cgroups 및 네임스페이스와 같은 커널의 기능을 사용하여 프로세스를 분리함으로써 독립적으로 실행될 수 있도록 한다

- Docker image
    
    - 도커 컨테이너를 구성하는 파일 시스템과 실행할 어플리케이션 설정을 하나로 합친 것으로, 컨테이너를 생성하는 템플릿 역할
    
    - 컨테이너 실해에 필요한 파일과 설정값등을 포함하고 있는 것으로 상태값을 가지지 않고 변하지 않는다

- Docker container

    - 도커 이미지를 기반으로 생성되며, 파일 시스템과 어플리케이션이 구체화되어 실행되는 상태
    
- Dockerfile

    - 필요한 패키지를 설치하고 동작하기 위한 자신만의 설정을 담은 파일이며 이것으로 이미지를 빌드 한다
    
- Docker Hub

    - 이미지들을 저장 관리해주며 배포도 가능하다
    
- 과정

    - 도커파일로 도커 이미지를 빌드, 이미지를 실행시켜 도커 컨테이너를 생성
    
    
### Docker file

- dockerfile은 필요한 패키지를 설치하고 동작하기 위한 자신만의 설정을 담은 파일이며 이미지를 빌드 한다

- dockerfile은 도커 명령어를 순서에 따라 빌드한다

- 명령어

    - FROM
    
        - 유효한 Dockerfile은 FROM 명령으로 시작해야 한다
        
        - 새 작업을 시작할 베이스 이미지를 지정한다
        
    - LABEL
    
        - 이미지에 메타데이터를 추가한다
        
            - 이미지의 버전 정보, 작성자, 코멘트와 같이 이미지 상세 정보를 작성해두기 위한 명령.
        
        - 아래 명령어로 이미지의 메타데이터를 확인할 수 있다
        
            ```js
            docker image inspect --format="{{ .Config.Labels }}" [이미지명]
            ```
                
    - RUN
    
        - 새 이미지 레이어를 만들어 내 명령을 실행하고 결과를 커밋한다
        
        - 백슬래시 ( \ )를 사용하여 다음 줄에 RUN 명령을 계속할 수 있다.
        
        - 주의 : 항상 apt-get update 와 apt-get install는 같은 RUN 실행중에서 동시에 실행해 캐싱 문제를 방지 (같은 결과를 가져오더라도 RUN을 여러줄로 작성하면 image layer가 여러개 생성되고, RUN을 한줄로 작성하면 image layer가 하나 생성된다.)
        
    - COPY
    
        - 호스트 OS의 파일 또는 디렉토리를 컨테이너 안의 경로로 복사한다
        
    - EXPOSE
    
        - 해당 컨테이너가 런타임에 지정된 네트워크 포트에서 수신 대기중이라는 것을 알려준다.
        
        - 일반적으로 dockerfile을 작성하는 사람과 컨테이너를 직접 실행할 사람 사이에서 공개할 포트를 알려주기 위해 문서 유형으로 작성할 때 사용한다
        
        - 이 명령 자체가 작성된 포트를 실행하여  listening 상태로 올려주거나 하지는 않기 때문에, 실제로 포트를 열기 위해선 container run에서 -p 옵션을 사용해야 한다
        
            ```js
            docker run -p 80:80/tcp -p 80:80/udp ...
            ```
                
        - 프로토콜을 지정하지 않으면 기본값은 TCP이다
        
    - CMD
    
        - 생성된 컨테이너를 실행할 명령어를 지정한다
        
        - 도커 파일에 CMD가 두 개 이상 있는 경우 마지막 CMD만 유효하다
    


### Debian

- 우분투 같은 리눅스 OS 종류 중 하나이다

- 안정성을 매우 중시하는 리눅스 배포판


### Nginx

- 무료로 제공되는 오픈소스 웹 서버 프로그램이다

- 웹 서버는 클라이언트로 부터 요청이 발생했을 때 요청에 맞는 정적 콘텐츠를 보내주는 역할을 한다

- 적은 자원으로 더 빠르게 데이터를 서비스 할 수 있다


### 웹 서버

- 웹 서버는 HTTP를 통해 웹 브라우저에서 요청하는 HTML 문서나 오브젝트(이미지 파일 등)을 전송해주는 서비스 프로그램을 말한다

- 그림, CSS, 자바스크립트를 포함한 HTML 문서가 클라이언트로 전달된다

- 과정

    - 클라이언트의 접속을 받아들이거나, 닫는다
    
    - HTTP 요청 메시지를 네트워크로부터 읽는다
    
    - 요청 메시지를 해석하고 행동을 취한다
    
    - 메세지에서 지정한 리소스에 접근한다
    
    - 올바른 헤더를 포함한 HTTP 응답 메시지를 생성한다
    
    - 응답을 클라이언트에게 돌려준다
    
    - 로그파일에 트랜잭션 완료에 대한 기록을 남긴다
    

### HTTP

- Hyper Text Transfer Protocol의 약자

- 주로 HTML 문서를 주고 받는데에 쓰인다

- 주로 TCP를 사용하고 80번 포트를 사용한다

- HTTP를 통해 전달되는 자료는 http:로 시작하는 URL로 조회할 수 있다



### phpMyAdmin 및 php-fpm

- php를 기반으로 mySQL의 GUI로서 웹에서 실행할 수 있는 프로그램이다

- php란?

    - 대표적인 서버 사이드 스크립트 언어이다
    
- CGI(공통 게이트웨이 인터페이스)란?

    - nginx는 웹서버이기 때문에 정적 콘텐츠밖에 다루지 못한다. 동적 페이지를 구현하기 위해서는 웹 서버 대신 동적 콘텐츠를 읽은 뒤 html로 변환시켜 웹 서버에게 다시 전달해주는 외부 프로그램(php 모듈)이 필요하다. 이런 연결 과정의 방법 혹은 규약을 정의한 것이 CGI이다.
    
- php-fpm (PHP FastCGI Process Manager) 란?

    - 일반 GCI 보다 빠른 처리가 가능한 FastGCI
    
    - php-fpm을 통해 nginx와 php를 연동시켜 우리의 웹 서버가 정적 콘텐츠 뿐만 아니라 동적 콘텐츠를 다룰 수 있도록 만드는 것이다
    
    
### HTTPS 및 SSL

- HTTPS(Hypertext Transfer Protocol over Secure Socket Layer)는 SSL 위에서 돌아가는 HTTP의 평문 전송 대신에 암호화된 통신을 하는 프로토콜이다.

- 정보를 암호화하고 신뢰할 수 있는 사이트인지 확인이 가능 할 수 있게 해준다

- HTTPS를 서버에서 구현하기 위해서는 신뢰할 수 있는 상위 기업이 발급한 인증서가 필요로 하는데 이런 발급 기관을 CA(Certificate authority)라고 한다. CA의 인증서를 발급받는것은 무료가 아니다

- self-signed SSL 인증서는 자체적으로 발급받은 인증서이며, 로그인 및 기타 개인 계정 인증 정보를 암호화한다. 브라우저는 신뢰할 수 없다고 판단해 접속시 보안 경고가 발생한다

- self-signed SSL 인증서를 만드는 방법은 몇 가지가 있는데, 무료 오픈소스인 openssl을 이용해 만들 수 있다

    - HTTPS를 위해 필요한 개인키(.key), 서면요청파일(.csr), 인증서파일(.crt)을 openssl이 발급해준다


### Autoindex

- 일반적으로 웹 서버 파일 시스템의 특별한 한 폴더를 웹 콘텐츠를 위해 사용한다. 이 폴더를 문서루트 혹은 docroot 라고 부른다. 리소스 매핑의 가장 단순한 형태는 요청 URI를 docroot 안에 있는 파일의 이름으로 사용하는 것이다.

- 만약 파일이 아닌 디렉토리를 가리키는 url에 대한 요청을 받았을 때는, 요청한 url에 대응되는 디렉토리 안에서 index.html 혹은 index.htm 으로 이름 붙은 파일을 찾아 그 파일의 콘텐츠를 반환한다. 이를 autoindex라고 부른다

- autoindex가 꺼져 있거나 해당 디렉토리에 index 목록에 해당하는 파일이 없다면, 웹 서버는 자동으로 그 디렉토리의 파일들을 크기, 변경일, 해당 파일에 대한 링크와 함께 열거한 HTML 파일을 반환한다

- 루트 디렉토리인 /var/www/html에 존재하는 index.nginx-debian.html을 주석처리해보면 전체 파일 목록을 반환해준다


# ft_server 시작

### 도커 설치

- [Docker Desktop for Mac](https://hub.docker.com/editions/community/docker-ce-desktop-mac/)에서 다운

- 도커 명령어

    - 컨테이너 조회
    
        ```js
        docker ps -a
        ```
            
    - 컨테이너 중지
    
        ```js
        docker stop <컨테이너 이름 혹은 아이디>
        ```
            
    - 컨테이너 시작 및 재시작
    
        ```js
        docker start <컨테이너 이름 혹은 아이디>
        ```
        
        ```js
        docker restart <컨테이너 이름 혹은 아이디>
        ```
            
    - 컨테이너 접속
    
        ```js
        docker attach <컨테이너 이름 혹은 아이디>
        ```
            
### 도커로 데비안 버스터 이미지 생성

```js
docker pull debian: buster
```

- docker images 명령어로 확인

    <p>
        <img width="641" alt="스크린샷 2021-03-28 오후 8 08 40" src="https://user-images.githubusercontent.com/48857296/112750106-7a878180-9001-11eb-843d-eb7b87b97e60.png">
    </p>
    

### 도커로 데비안 버스터 환경 실행 및 접속

```js
docker run -it --name con_debian -p 80:80 -p 443:443 debian:buster
```
    
<p>
    <img width="834" alt="스크린샷 2021-03-28 오후 8 18 26" src="https://user-images.githubusercontent.com/48857296/112750297-d1418b00-9002-11eb-894d-272b4742c12e.png">
</p>
    
- 명령어

    - run

        - 새 컨테이너에서 명령 실행
    
    - -it
    
        - -i와 t를 동시에 사용한 것으로 터미널 입력을 위한 옵션
    
        - -i는 STDIN 표준 입출력을 열다 -t는 가상 tty (pseudo-TTY, 터미널) 를 통해 접속하겠다는 의미이다
    
    - -p

        - 컨테이너와 호스트의 포트를 연결 (포워딩)
        
        - [컨테이너 포트와 호스트 포트 관련 설명](https://blog.naver.com/alice_k106/220278762795)
        
        - [포트포워딩 관련 설명](https://dololak.tistory.com/390)
        
    - --name
    
        - 컨테이너의 이름을 설정한다
    
- -p 80:80은 호스트 ip 80번 포트로 접속하면 도커 컨테이너의 80번으로 접속이 가능하다는 뜻이다

- Docker host에 container가 배포되면 각 container에는 격리된 네트워크 환경(namespace)이 제공된다.

- 이 네트워크 환경은 오로지 각각의 container만을 위한 네트워크 환경이다.

- 각 container에는 통신을 위한 인터페이스도 새롭게 할당되며, private IP도 부여 받게 된다.


### 데비안 버스터에 Nginx, cURL 설치

```js
apt-get update
apt-get upgrade
apt-get -y install nginx curl
```

- apt-get을 업데이트,업그레이드 해주고 -y라는 yes 옵션을 넣어 nginx와 curl을 설치해준다

- cURL

    - 서버와 통신을 할 수 있는 커맨드 명령어 툴이다
    
    - http 프로토콜을 이용해 웹 페이지의 소스를 가져온다거나 파일을 다운받을 수 있다
    
    - ftp 프로토콜을 이용해서 파일을 받거나 올릴 수도 있다
    
    - [curl 사용법](https://shutcoding.tistory.com/23)
    
- nginx가 설치가 잘 되었는지 확인을 위해 다음 명령어를 실행한다
    
    ```js
    service nginx start
    ```
        
    <p>
        <img width="328" alt="스크린샷 2021-03-28 오후 8 31 48" src="https://user-images.githubusercontent.com/48857296/112750653-c4be3200-9004-11eb-9e0f-a48033ebb914.png">
    </p>

- window에서는 ipconfig, mac에서는 ifconfig | grep inet를 통해 ip 주소를 얻은 후 브라우저의 domain 창에 치거나 localhost를 입력하면 다음과 같이 나온다

    <p>
        <img width="908" alt="스크린샷 2021-03-28 오후 8 43 38" src="https://user-images.githubusercontent.com/48857296/112750964-57130580-9006-11eb-8806-7cc8c3b34a4d.png">
    </p>

- 설치한 curl를 사용해 터미널을 통해서도 확인할 수 있다

    <p>
        <img width="612" alt="스크린샷 2021-03-28 오후 9 07 49" src="https://user-images.githubusercontent.com/48857296/112751599-d48c4500-9009-11eb-80e2-483dbc3c1949.png">
    </p>
    
### SSL 인증서 생성
        
- openssl을 설치한다

    ```js
    apt-get -y install openssl
    ```

- 개인키 및 인증서 생성

    ```js
    openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
    ```

    - localhost.dev.key와 localhost.dev.crt가 생성된다
    
    - 명령어와 옵션
    
        - req : 인증서 요청
        
        - -newkey : 개인키 생성을 위한 옵션
        
        - -keyout <name> : <name>이란 이름으로 키 파일을 생성
        
        - -out <crt_name> : <crt_name>이란 이름으로 인정서를 생성
        
        - nodes : 이 옵션은 개인키를 암호화하지 않기 위한 옵션이다. 이 옵션이 없을 경우 최소 4자의 암호를 입력해야한다
        
        - x509 : 인증서 요청 대신 자체 서명된 인증서를 출력하는 옵션으로 테스트 인증서 혹은 자체 서명된 루트 CA를 생성하는 데 사용한다
        
        - subj"" : subject를 입력하기 위한 옵션으로 해당 옵션과 뒤의 내용을 기입하지 않으면 표준으로 입력해주어야 한다. CN의 경우 사용하려는 domain이름과 같아야 한다
        
            - C : ISO 국가 코드 KR, US, CN, JP (대문자)
            
            - ST : 시, 도
            
            - L : 구, 군
            
            - O : 기관명, 회사명
            
            - OU : 조직명
            
            - CN : 도메인명, 일반이름, IP 주소는 CN으로 사용할 수 없다
            
            - 위 항목은 모두 영문으로 입력해야 하며 특수문자를 사용하면 안된다
    
    <p>
        <img width="1328" alt="스크린샷 2021-03-28 오후 9 23 38" src="https://user-images.githubusercontent.com/48857296/112752031-ee2e8c00-900b-11eb-8bd4-7bf387a65ec7.png">
    </p>

- 권한 제한

    ```js
    mv localhost.dev.crt etc/ssl/certs/
    ```
    
    > 나중에 default 파일에서 서버설정할때 위치 인증서와 키 위치를 적어준다
    
    ```js
    mv localhost.dev.key etc/ssl/private/
    ```

    > 나중에 default 파일에서 서버설정할때 위치 인증서와 키 위치를 적어준다
    
    ```js
    chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key
    ```
    
    > root 계정에 권한을 준다
    
### nginx에 SSL 설정 및 url redirection 추가

- etc/nginx/sites-available/default 파일을 수정해줄건데, 좀 더 편한 접근을 위해 vim을 설치한다
    
    ```js
    apt-get -y install vim
    vim etc/nginx/sites-available/default
    ```
    
- default 파일에 https 연결을 위한 설정을 작성한다

- 원래는 서버 블록이 하나이며 80번 포트만 수신대기 상태인데, https 연결을 위해 443 포트를 수신대기하고 있는 서버 블록을 추가로 작성해준다

    <p>
        <img width="823" alt="스크린샷 2021-03-28 오후 9 41 20" src="https://user-images.githubusercontent.com/48857296/112752511-639b5c00-900e-11eb-87f0-3f15634e82da.png">
    </p>


    <p>
        <img width="821" alt="스크린샷 2021-03-28 오후 9 44 41" src="https://user-images.githubusercontent.com/48857296/112752623-e02e3a80-900e-11eb-9966-d40cae695a8a.png">
    </p>
    
    - 80번 포트로 수신되면 443 포트로 리다이렉션 시켜준다
    
    - 443 포트를 위한 서버 블록에는 ssl on과 인증서의 경로를 작성해준다
    
    - listen 80
    
        - 서버 블록은 지정된 도메인의 포트 80에서 들어오는 연결을 수신한다
        
    - listen [::]:80
    
        - listen 80과 동일하지만 모든 IPv6 HTTP 트래픽에 대해 작동한다
        
    - return 301 https://$host$request_uri;
    
        - "301"은 트래픽을 redirection하는 데 사용된다
        
        - "https://$host$request_uri;"는 모든 트래픽이 redirection되는 대상을 뜻한다
        
            - http://localhost/index.php 라는 URL로 접속한다면 host=localhost, request_uri=index.php가 되는 것이다
    
    
- 바뀐 설정을 nginx에 적용하기 위해 다음 명령어를 사용한다

    ```js
    service nginx reload
    ```
        
- 브라우저에서 https://localhost로 접속했을 때 경고문구가 다음과 같이 뜬다

    <p>
        <img width="1325" alt="스크린샷 2021-03-28 오후 9 48 32" src="https://user-images.githubusercontent.com/48857296/112752762-85e1a980-900f-11eb-9aee-dcd6e40c4aad.png">
    </p>

    - 세부사항 보기를 눌러 웹사이트 방문을 누른 후 host의 비밀번호를 입력 하면 접속 할 수 있다
    
    - http://localhost, http://loaclhost:80, https://localhost:443을 접속하여 redirection이 잘 되었는지 확인한다
    
- SSL 확인

    - url 옆에 있는 자물쇠를 클릭하여 인증서의 세부사항을 보면 다음 그림과 같이 인증서가 등록된 것을 볼 수 있다
    
        <p>
            <img width="586" alt="스크린샷 2021-03-28 오후 9 59 56" src="https://user-images.githubusercontent.com/48857296/112753057-1076d880-9011-11eb-9b87-c6468bcc85e1.png">
        </p>


### php-fpm 설치 및 nginx 설정

- nginx는 웹서버이면서 정적인 콘텐츠만을 제공한다. 동적 페이지를 구현하기 위해서 웹 서버 대신 동적 콘텐츠를 읽은 뒤 html로 변환시켜 웹 서버에게 다시 전달해주는 외부 프로그램(php 모듈)이 필요하다

- 동적 페이지를 구현하기 위해 php를 사용한다

- php란?

    - PHP(PHP: Hypertext Preprocessor)는 C언어를 기반으로 만들어진 서버 측에서 실행되는 서버 사이드 스크립트 언어다. PHP로 작성된 코드를 HTML 코드 안에 추가하면, 웹 서버는 해당 PHP 코드를 해석하여 동적 웹 페이지를 생성한다.
    
- DB작업도 할것이고 사용자 즉 클라이언트의 행도엥 따라 즉시 웹페이지 화면이 바뀌는 동적인 웹페이지를 제공해야 하기 때문에 php-fpm를 사용하여 nginx와 php를 연동시켜주는 것이다

- php-fpm 7.3 버전을 설치한다

    ```js
    apt-get -y install php-fpm
    ```

- fpm-php와 nginx를 연동하기 위해 default파일을 수정한다

    ```js
    vim /etc/nginx/sites-available/default
    ```

    <p>
    <img width="823" alt="스크린샷 2021-03-28 오후 10 07 09" src="https://user-images.githubusercontent.com/48857296/112753389-68620f00-9012-11eb-8650-db2a310aea12.png">
    </p>
    
    > 수정 전
    
    <p>
    <img width="821" alt="스크린샷 2021-03-28 오후 10 08 28" src="https://user-images.githubusercontent.com/48857296/112753400-744dd100-9012-11eb-8e2a-dccef9ff9df2.png">
    </p>
    
    > 수정 후

- php-fpm 작동 확인

    ```js
    service php7.3-fpm start
    service php7.3-fpm status
    service nginx restart
    ```
    
    - 설정 파일들의 의미와 원리
    
        - sites-available
        
            - 가상 서버 환경들에 대한 설정 파일들이 위치하는 부분. 가상 서버를 사용하거나 사용하지 않던간에 그에 대한 설정 파일들이 위치하는 곳이다
            
        - sites-enabled
        
            - sites-available에 있는 가상 서버 파일들중에서 실행시키고 싶은 파일을 symlink로 연결한 폴더. 실제로 이 폴더에 위치한 가상서버 환경 파일들을 읽어서 서버를 세팅한다
            
        - nginx.conf
            
            - Nginx에 관한 설정파일로 Nginx 설정에 관한 블록들이 작성되어 있으며 이 파일에서 sites-enabled 폴더에 있는 파일들을 가져온다
            
        - sites-available은 일단 웹서버에 대한 설정 파일들을 작성 할 수 있다. 그러나 실제로 컴퓨터는 sites-enabled에 있는 파일들을 읽어서 웹서버 환경을 구축한다. 그럼 어떻게 sites-available파일을 수정 했는데 환경이 바뀌는가?? 바로 심볼릭링크이다. 심볼릭링크를 걸어놔서 sites-available에 있는 default파일을 수정하면 sites-enabled에도 반영 되는 것이다. 그러면 sites-available에 환경을 설정할 수있는 여러 파일들을 미리 비축해서  나중에 사용하고 싶은 환경을 심볼릭 링크로 걸어주면 된다.
        
            - [참고](twpower.github.io/50-make-nginx-virtual-servers)
            
    
### autoindex 설정

- autoindex의 기능은 URL로 접근해서 index목록에 해당하는 파일이 없다면 리스트 형태로 파일들을 보여주는 옵션이다

    ```js
    vim /etc/nginx/sites-available/default
    ```
        
    - 위의 명령어를 통해 다음 그림과 같이 default를 수정해준다
    
        <p>
            <img width="427" alt="스크린샷 2021-03-28 오후 10 38 07" src="https://user-images.githubusercontent.com/48857296/112754282-52eee400-9016-11eb-9882-9f12abcf36a5.png">
        </p>

        - 만약 autoindex가 꺼져 있거나 해당 디렉토리에 index 목록에 해당하는 파일이 없다면, 웹 서버는 자동으로 그 디렉토리의 파일들을 크기, 변경일, 해당 파일에 대한 링크와 함께 열거한 HTML 파일을 반환한다
        
        - /var/www/html 에 존재하는 index.nginx-debian.html을 주석처리해보면 다음과 같이 확인해볼 수 있다

        
            <p>
                <img width="1096" alt="스크린샷 2021-03-28 오후 10 46 35" src="https://user-images.githubusercontent.com/48857296/112754543-7f573000-9017-11eb-9426-0d676c4d7745.png">
            </p>


### MariaDB(mysql) 설치 및 계정 생성

```js
apt-get -y install mariadb-server php-mysql
```

> 컨테이너에 mysql 설치

```js
service mysql start
```

> mysql 서비스 가동

```js
mysql -u root
```

> root 계정으로 mysql 접속

```js
create database wordpress;
```

> wordpress라는 데이터베이스(스키마) 생성

```js
CREATE USER 'yong-lee'@'localhost' IDENTIFIED BY '1234';
```

> yong-lee라는 계정생성, 비밀번호 1234

```js
GRANT ALL PRIVILEGES ON wordpress.* TO 'yong-lee'@'localhost' WITH GRANT OPTION;
```

> @'localhost' 는 로컬 접속만 허용하겠다는 뜻이고 @'%'로 작성하면 외부 접속을 허용하겠다는 뜻이다.

> yong-lee 이란 계정에 wordpress라는 데이터베이스에 대하여 권한을 줌 


### wget 설치

```js
apt-get install -y wget
```

> wget을 설치한다


### Wordpress 설치

- 설치 및 압축해제

    ```js
    wget https://wordpress.org/latest.tar.gz
    tar-xvf latest.tar.gz
    mv wordpress/ var/www/html
    ```

    - 워드프레스 최신버전을 받은 후 압축을 해제 한다
    
    - 압축 해제 후 wordpress를 html로 옮긴다

- 유저 그룹 권한 설정

    ```js
    chown -R www-data:www-data /var/www/html/wordpress
    ```

    - 유저 그룹 권한 설정

    - nginx.conf를 보면 user로 www-data가 작성되어있다

    - wordpress의 유저 그룹을 그에 맞게 설정해준 것이다

- wp-config.php 파일 수정

    - wp-config-sample.php을 복사해 wp-config.php를 만든다
        
        ```js
        cp -rp var/www/html/wordpress/wp-config-sample.php var/www/html/wordpress/wp-config.php
        ```
    - wp-config.php 파일의 DB_NAME, DB_USER, DB_PASSWORD 3가지 항목을 수정해준다
    
        ```js
        vim var/www/html/wordpress/wp-config.php
        ```
        
    <p>
        <img width="496" alt="스크린샷 2021-03-29 오전 2 13 56" src="https://user-images.githubusercontent.com/48857296/112761115-90fb0080-9034-11eb-998d-be090e5888ad.png">
    </p>

    - service php7.3을 다시 리로드 한다
    
        ```js
        service php7.3-fpm restart
        ```
        
    - localhost/wordpress에 접속하여 밑의 그림과 같이 나오면 한국어로 설정 후 wordpress 관리툴을 회원가입하면 된다
        
        <p>
            <img width="797" alt="스크린샷 2021-03-29 오전 2 29 38" src="https://user-images.githubusercontent.com/48857296/112761529-a96c1a80-9036-11eb-9000-c80fc40ab0aa.png">
        </p>
    
        <p>
            <img width="1320" alt="스크린샷 2021-03-29 오전 2 45 14" src="https://user-images.githubusercontent.com/48857296/112762057-dcafa900-9038-11eb-822b-c7003c371d67.png">
        </p>
        
- DB 연동 확인

    ```js
    mysql -u root
    use wordpress;
    show tables;
    ```

    - 위 명령어를 차례로 실행하면 다음 그림과 같이 나온다
    
        <p>
            <img width="818" alt="스크린샷 2021-03-29 오전 2 47 04" src="https://user-images.githubusercontent.com/48857296/112762121-197ba000-9039-11eb-8010-12fef091c26e.png">
        </p>


### phpmyadmin 설치 및 설정

- phpmyadmin은 웹에서 DB를 관리할 수 있게 해준다

- phpmyadmin 설치

    ```js
    wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
    ```
    
    > 웹 다운로드 실행
    
    ```js
    tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
    ```
    
    > 파일압축 풀기
    
    ```js
    mv phpMyAdmin-5.0.2-all-languages phpmyadmin
    ```
    
    > 파일명을 phpmyadmin으로 변경
    
    ```js
    mv phpmyadmin /var/www/html/
    ```
    
    > phpmyadmin 폴더를 엔진엑스 웹스파일들이 모여있는 곳으로 이동
    

- 쿠키 권한을 위한 blowfish 암호설정

    - phpmyadmin 폴더에 config.sample.inc.php을 복사해 config.inc.php 파일을 만든다
    
        ```js
        cp -rp var/www/html/phpmyadmin/config.sample.inc.php var/www/html/phpmyadmin/config.inc.php 
        ```
    
    - 파일을 만들었으면 파일 안에 있는 blowfish_secret 설정을 해준다
    
        ```js
        vim var/www/html/phpmyadmin/config.inc.php
        ```

        - blowfish password 생성 사이트를 접속하여 생성된 코드로 바꿔준다
        
            - [blowfish secret generator](https://phpsolved.com/phpmyadmin-blowfish-secret-generator/?g=[insert_php]echo%20$code;[/insert_php])
             
            <p>
                <img width="711" alt="스크린샷 2021-03-30 오전 3 26 35" src="https://user-images.githubusercontent.com/48857296/112882342-cde3f780-9107-11eb-9160-770dec87f190.png">
            </p>

            
            <p>
                <img width="758" alt="스크린샷 2021-03-30 오전 3 29 42" src="https://user-images.githubusercontent.com/48857296/112882682-3a5ef680-9108-11eb-91bf-6213b47a72ba.png">
            </p>

- phpmyadmin 로컬로 접속하기

    - https://localhost/phpmyadmin에 접속한 뒤 wordpress/wp-config.php 에서 설정한 ID와 PW를 입력하면 데이터베이스를 GUI로 편리하게 관리할 수 있다


# Dockerfile 만들기

### 해야할 것

- 지금까지 만들어온 프로젝트를 srcs, Dockerfile, 쉘스크립트에 잘 나눠 담으면 된다

    - srcs : 사용자가 직접 작성하기 복잡한 설정파일들
    
        1. etc/nginx/sites-available/default

            - nginx 서버의 ssl, autoindex, redirection 설정파일.

        2. var/www/html/phpmyadmin/config.inc.php

            - blowfish 설정파일.

        3. var/www/html/wordpress/wp-config.php

            - mysql의 wordpress DB 설정파일.

        4. run.sh

    - Dockerfile : 프로젝트 구축에 필수적인 패키지 설치 명령어들
    
        - nginx
        
        - php7.3-fpm
        
        - mariadb-server, php-mysql, php-mbstring
       
        - openssl
        
        - vim
        
        - wget

    - 쉘스크립트(run.sh) : 그 외 프로젝트 설정을 위해 작성했던 모든 명령어들
    

### Dockerfile 작성하기

```js
FROM    debian:buster //프로젝트를 시작할 베이스 image를 지정

LABEL    maintainer="yong-lee@student.42seoul.kr"  //image에 metadata를 추가한다

RUN    apt-get update && apt-get install -y \
    openssl \
    wget \
    nginx \
    vim \
    php7.3-fpm \
    mariadb-server \
    php-mysql \
    mariadb-server \
    php-mysql \
    php-mbstring
// 쉘 명령어를 실행하고 결과를 커밋한다

COPY    ./srcs/default ./
COPY    ./srcs/run.sh ./
COPY    ./srcs/DB.sql ./
COPY    ./srcs/wp-config.php ./
COPY    ./srcs/config.inc.php ./
// HostOS의 파일 또는 디렉토리를 컨테이너 안의 경로로 복사한다

EXPOSE 80 433
// 이 컨테이너가 해당 포트를 사용할 예정임을 사용자에게 알려준다.
// 실제로 포트를 열기 위해서는 run 명령어에서 -p 옵션을 사용해야한다.

CMD bash run.sh
// 생성된 컨테이너를 실행할 명령어를 지정한다
```

### container 내부의 파일들 hostOS/srcs 폴더로 옮기기

        - docker cp [container name]:[container 내부 경로] [host 파일경로]

### run.sh 작성하기

- 빌드 자동화를 위한 쉘 스크립트를 작성한다

- 작성법

    - 헤더
    
        - 아래 내용을 파일 상단에 써주면, 뒤에 나오는 코드를 모두 bash 명령어로 인식한다
        
                - #!/bin/bash
            
    - 개행
    
        - 모든 명령어는 개행을 기준으로 순서대로 실행된다
        
    - 주석
    
            - #을 사용한다
            
    - 변수
    
        - = 을 이용해서 선언하고 ${변수명} 으로 사용한다
        
        - = 는 공백 없이 붙여써야한다
        
        - "" 로 감싸서 사용하면 더 안전하다. (문자열에 공백도 포함해서 값을 이용할 수 있기 때문이다)
        
        - 지역변수에는 local을 붙인다
        
            ```js
            #!/bin/bash
            
            test="abc"
            num=100
            
            echo "${test}"
            echo "${num}"
            ```
            
    - 백그라운드 실행
    
        - 한 명령어를 실행하는 동안 다른 명령어를 수행하고 싶다면 &를 사용하면 된다
        
                - [파일명] &
                
    - 더 다양한 문법
    
        - [간단한 쉘 스크립트 문법 정리와 예제](https://twpower.github.io/131-simple-shell-script-syntax)
        
    - 실행방법
    
        ```js
        $ ./파일명
        $ sh 파일명
        $ bash 파일명
        ```
        
### Dockerfile 빌드하기

        - docker build <옵션> <Dockerfile 경로>
        
- 도커의 build 명령어를 사용한다. 

- -t 옵션을 사용하면 저장소 이름, 이미지 이름, 태그를 설정할 수 있다.

- <저장소 이름> /<이미지 이름>:<태그> 형식

- 아래 처럼 빌드 했을 때 localhost에 접속할 수 있다

    ```js
    docker build . -t ft_server
    
    docker run -it -p80:80 -p443:443 ft_server
    ```
        
