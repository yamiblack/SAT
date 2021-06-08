# Smart Arduino Trash bin
- 강의명 : 2019학년도 1학기 임베디드 시스템 개론
- 팀명 : 복재인간
  - [이주형][member1]
  - [신영환][member2]
  - [강지웅][member3]
  - [김진산][member4]
  - [이재욱][member5]
 </br>
 
## 서비스 소개
- Arduino의 스텝모터, 초음파 거리센서, LCD, 그리고 RGB LED를 이용하여 쓰레 기를 자동으로 압축하고 잔량을 표시한다.
</br>

## 시연 이미지
<p align="center"> <img src="https://user-images.githubusercontent.com/50551349/121200399-aa2ef180-c8ae-11eb-880a-a27881c4f817.gif" width="500"></p>

- 쓰레기통이 열렸다가 닫히면 스텝모터가 작동하면서 쓰레기통에 있는 쓰레기를 압축한다. 

<p align="center"> <img src="https://user-images.githubusercontent.com/50551349/121200356-a13e2000-c8ae-11eb-942d-4186f04404c5.gif" width="500"></p>

- 압축된 쓰 레기의 높이를 초음파 거리센서가 측정하여 쓰레기통의 잔량을 LCD는 퍼센트(%)로, RGB LED는 색으로 출력한다. 쓰레기 높이가 60% 이하이면 녹색, 쓰레기 높이가 90% 이상이면 적색을 확인할 수 있다.

</br>


## 사용 센서
<p align="center"> <img src="https://user-images.githubusercontent.com/50551349/121198926-7901f180-c8ad-11eb-81ae-17ef117d0c43.jpg" width="500"></p>

- 스텝모터에 줄을 연결하고, 반대쪽 끝에 쓰레기에 압력을 가할 수 있는 판을 부착해 압축 도구로 활용했다.   

<p align="center"> <img src="https://user-images.githubusercontent.com/50551349/121198930-799a8800-c8ad-11eb-80c5-0af0db84fd05.jpg" width="500"></p>

- 초음파 거리센서를 쓰레기통이 열렸는지, 그리고 쓰레기통에 존재하는 쓰레기의 양을 인식하는 장치로 활용했다.   

<p align="center"> <img src="https://user-images.githubusercontent.com/50551349/121198923-78695b00-c8ad-11eb-8359-ea5d690934e2.jpg" width="500"></p>

-  LCD의 화면으로 쓰레기통의 잔량을 퍼센트(%)로 표시해주는 장치로 활용했다.   

<p align="center"> <img src="https://user-images.githubusercontent.com/50551349/121198911-76070100-c8ad-11eb-8d5a-57680f7e9e5d.jpg" width="500"></p>

- RGB LED는 쓰레기통 잔량에 따라 점등하는 색을 다르게 하여 직관적인 알림 장치로 활용했다. 쓰레기의 높이가 60% 이하면 녹색, 60~90%는 황색, 그리고 90% 이상은 적색으로 설정했다. 다른 3색의 LED 사용보다는 깔끔하고 핀의 사용이 적은 RGB LED를 사용했다.   

</br>

## 센서 연결
<p align="center"> <img src="https://user-images.githubusercontent.com/50551349/121198931-799a8800-c8ad-11eb-8632-dd26704aef23.jpg" width="40%"> <img src="https://user-images.githubusercontent.com/50551349/121199153-a9e22680-c8ad-11eb-9965-8f3151c5391a.png" width="40%"></p>

- 핀의 개수가 제한적인 점, 그리고 유선 장비인 점을 고려해 좌측의 그림과 같이 4개의 센서를 연결했다. 잔량을 나타내는 LCD와 RGB LED를 하나의 보드에, 그리고 초음파 거리센서는 별도의 보드에 설치했다. 쓰레기통에 부착할 것을 고려해 초음파 거리센서의 보드는 최대한 긴 케이블을 이용해 연결했다. 우측의 그림은 직접 쓰레기통을 제작하여 센서들을 부착한 모습이다.
</br>

## 기술 스택
- Arduino
</br>

[member1]:https://github.com/yamiblack
[member2]:https://github.com/sin111011
[member3]:https://github.com/JIW00NG
[member4]:https://github.com/lazybones1
[member5]:https://github.com/lee-jaewook
