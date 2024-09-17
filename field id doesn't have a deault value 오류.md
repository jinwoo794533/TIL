# field id doesn't have a deault value 오류



![스크린샷 2021-09-06 오후 3.54.04](/Users/anjin-u/Library/Application Support/typora-user-images/스크린샷 2021-09-06 오후 3.54.04.png)

 Member Domain을 위와 같이 만든 뒤 간단히 auth 시스템을 구현하였다. 

그랬을 때 field id doesn't have a deault value 라는 에러가 떴는데 눈으로 읽기만 해도 대체 왜 이게 뜨지 하는 생각이 든다. strategy = GenerationValueType.identity

를 입력해주었음에도 이러한 문제가 발생한다는 것이 이해되지 않았다. 그리하여 구글에 검색해보았음에도 나에게 해당하는 문제 해결 방안은 나오지 않았다. 그리하여 DB를 뜯어보니...



db를 고치기 전에 생성해놓았던 자료 하나가 남아있었으며, 구조 또한 바뀌기 전이었다. 

application.yml에서 ddl-auto : create로 설정했음에도 왜 이러한 일이 발생한 것인지 이해되진 않지만 일단 이것이 문제라 보고 table을 삭제한 뒤 요청을 넣으니....





![스크린샷 2021-09-06 오후 4.00.57](/Users/anjin-u/Library/Application Support/typora-user-images/스크린샷 2021-09-06 오후 4.00.57.png)







고쳐졌다.