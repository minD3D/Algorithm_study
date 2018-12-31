알고리즘 종류
-----------

1. 재귀호출, 백트래킹
DONE
2. 그리디
DONE
3. 다이나믹 (Dynamic Programming)
DONE
4. 기하 알고리즘
    - 내부-외부 판별
    - 단순 닫힌 경로
    - Convex Hull (Graham Scan 또는 Jarvis March. 전자를 추천)
    - 선분의 교차
    - 벡터 외적 (벡터곱)
    - Rotating Calipers   (꼭 알 필요는 없지만, 알아두면 좋습니다)

5. 문자열 & 오토마타 & 구조
    - KMP (Knuth-Morris-Pratt) 스트링 매칭
    - Boyer Moore 스트링 매칭
    - 유한 오토마타 (Finite Automata)
    - Trie 구조 (이것은 꼭 알 필요는 없습니다)

6. 수학 & 정수론 부분
    - 유클리드 호제법
    - 에라스토테네스의 체
    - 페르마 소정리
    - Totient Function (오일러 함수를 말합니다)
    - Stern-Brocot Tree (스턴-브로콧 트리)
    - Miler Rabin 소수 판정, Pollard Rho의 소인수분해 방법  (꼭 알 필요는 없습니다)
    - 포함배제의 원리

7. 근사 알고리즘
    - 국소탐색 (LS ; Local Search)
    - 시뮬레이티드 어닐링 (Simulated Annealing)
    - 유전자 알고리즘 (GA)    (꼭 알 필요는 없습니다)

8. NP 문제
    - Minimum Vertex Cover, Edge Cover , Maximum Independent Set
    - 헤밀턴 회로
    - TSP

  

그래프 & 자료구조
--------------

1. 검색 (이분검색, 이진검색트리)
    - 여기서 이진검색트리의 최악의 경우 시간복잡도를 줄이기 위해서 AVL Tree가 구현
      레드블랙트리는 AVL의 일종
DONE
2. 스택, 큐
DONE
3. Deque (Double Ended Queue) 

4. 링크드리스트 (Linked List)

5. 힙 구조
   - Binary Heap
   - Binomial Heap
   - Fibonacci Heap 
   - (Binary) Indexed Tree  
   - Interval Tree 

6. 정렬 (합병정렬, 퀵정렬, 힙정렬, 버블정렬, 선택정렬, 삽입정렬, 기수정렬)
   - K번째 숫자를 최악의 경우 O(n)에 찾는 문제

7. 최소비용신장트리
   - Prim
   - Kruskal
   - Matroid Theory  (이것도 꼭 알 필요는 없습니다)

8. 최단경로
   - Dijkstra (다익스트라)
   - Floyd (플로이드)
   - Bellman Ford (벨만포드)
DONE
9. 그래프 탐색
   - BFS(너비우선탐색), DFS(깊이우선탐색)
DONE
10. 위상정렬 (Topological Sort)

11. 최대유량 알고리즘 (Maximum Flow Algorithm)
   - Ford-Fulkerson의 방법
   - Minimum Cut (최소 절단 문제)
   - 푸시-재명명 방법 
   - 최대 이분매칭 (Bipartite Maximum Matching)
            - Hungarian Method  (가중치가 들어간 매칭)
            - Gale-Shapely Matching 
            - Hopcroft-Karp의 방법
   - Mincost-Maxflow Algorithm
   - Stoer-Wagner Algorithm   (간선연결도 문제에 쓰이는 최적 알고리즘)

12. 트리 관련
   - 최소 비용 채색 문제
   - 절점 찾기
   - Bridge 찾기
DONE
13. 강한 연결 성분 (Strongly Connected Components , 줄여서 SCC)
   - Kosaraju , Tarjan의 방법

14. 2-CNF (2-SAT의 일종입니다)

15. 서로소 집합 (Disjoint Set)
   - 순위 정하기 (휴리스틱의 일종)
   - 경로 압축 (휴리스틱의 일종 , Path Compression)