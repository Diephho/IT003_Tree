# IT003_Tree
Báo cáo thực nghiệm đo chiều cao cây AVL và cây Đỏ Đen
![image](https://github.com/Diephho/IT003_Tree/assets/126962960/3a55bea6-b8bd-4344-a1b1-134982f6b88b)
![image](https://github.com/Diephho/IT003_Tree/assets/126962960/70480bd5-e942-49a1-82a6-385fd1760726)

## Báo cáo nhận xét thực nghiệm: 
*Dựa trên thực nghiệm 10 bộ test ngẫu nhiên với mỗi bộ khoảng 10^6 giá trị.
-	Chiều cao cây Đỏ Đen lớn hơn chiều cao cây AVL ở cả 10 bộ test.
-	Chiều cao cây AVL dao động trong khoảng từ log2N đến 1.45log2N (đúng với 10 bộ test trên). 
-	Trong khi đó, chiều cao cây Đỏ Đen đều lớn hơn log2N ở tất cả các bộ test.
-	Chiều cao nhỏ hơn 1.45log2N đối với các bộ test: 2, 3, 4, 8, 9.
-	Đối với các bộ test còn lại (1, 5, 6, 7, 10), chiều cao cây Đỏ Đen lớn hơn so với 1.45log2N.
- Cây Đỏ Đen không bị giới hạn ở chiều cao 1.45log2N mà có thể cao hơn, cụ thể thông qua thực nghiệm và tài liệu thì chiều cao cây Đỏ Đen có thể đạt lớn nhất bằng 2log2(N+1).

 Chiều cao cây AVL: [log2N; 1.44log2N]
 
 Chiều cao cây Đỏ Đen: [log2N; 2log2(N+1)]
