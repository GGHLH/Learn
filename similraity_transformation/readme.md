# 人脸对齐的相似变换

## 人脸对齐
        人脸识别第一步骤：将检测到的人脸和人脸关键点(landmarks),都要对齐的我的标准人脸模板上。我们采用相似变换的方法
        
## 相似变换
        在于4个自由度和6个自由度之间的区别；
            -- 4个自由度：不会发生WarpAffine后错切，扭曲的情况；
$$M=
\left\{
 \begin{matrix}
   cos\theta*s & sin\theta*s & ox\\
   -sin\theta*s & cos\theta*s & oy\\
  \end{matrix} 
\right\}
$$
实际上这里zhi存在4个自由度，即
$$ cos\theta*s, \quad sin\theta*s, \quad ox, \quad oy
$$
这里请注意
$$ cos\theta*s \neq sin\theta*s \quad 当不相等时，为不等比列缩
$$
$$
  -sin\theta*s \neq cos\theta*s \quad 当不相等时， 为错切
$$

            -- 6个自由度：在WarpAffine后会发生错切，扭曲的情况；
                        当6个自由度时候这里的缩放，我们必须要是x、y同时等比缩放，而非拉伸的缩放方式造成图像扭曲，这是我们不想看到的
            
所以再做相似变换的时候一定要选取4个自由度的方法；
        
## 所需知识点
        
        1.需要了解矩阵的运算，矩阵的转置，伴随矩阵，逆矩阵的求解，奇异矩阵；
        2.最小二乘法 ， minimize的方向入手

最小二乘法：


$$
设：Y =Ax_0\quad \quad \quad \quad \quad \quad \quad \quad \quad \quad  \\
定义x_0为输入图像输入矩阵，Y为标准脸模板矩阵。A为将输入映射到标准脸模板的映射矩阵\\
Y =Ax_0:\leftarrow x_0为图像输入矩阵; \quad \\
Y =Ax_0:\leftarrow A我们需要求解的值; \\
Y =Ax_0:\leftarrow Y为标准脸模板矩阵; \\
则有某个变量x^`_0 = x_0A,我们需要最小化的minnimize\sum(x^`_0 - Y),即当A取何值时x^`_0 \rightarrow Y无限接近于Y，\\
即minimize\sum(x_0A-Y)^2,\\
通过控制A(映射矩阵)来使得输入的图像和标准脸无限接近，如下所示：\\
A=(x_0^T*x_0)^- x_0^T*Y

$$
通过矩阵求解最小二乘法就是:
$$
<1>. \quad x_0^T*Y=A(x_0^T*x_0):\quad \leftarrow俩边同乘x_0的转置  
$$
$$
<2>. \quad(x_0^T*x_0)^- x_0^T*Y=A:\quad \leftarrow左乘(x_0^T*x_0)的秩 
$$


