简历重点内容：  
1） 熟悉AI框架，快速适配硬件的  
2）Python c++ 能力强，熟悉大模型框架 训练推理流程之类的。  
3） 懂推理框架原理。  
  

教育背景：  
宁夏大学， 硕士（全日制）   
* 计算机科学与技术（计算机网络，边缘计算方向）    
北京邮电大学， 学士  
* 计算机科学与技术  
职业经历：  
中国移动公司甘肃分公司， 职员  
* 管理‘省级数字家庭管理平台’，负责对接第三方开发人员，整理需求以及功能验证等工作。主要以沟通协调各方资源为主。  
极客宸星， 兼职c++讲师
* 讲解c++基础语法知识，以及简单的数据结构和算法相关内容。
西安三星电子研究所， 职员 
* 负责大模型结构分析，以及利用xxx-xxx 硬件给大模型推断加速的可能性。xxx硬件是可以加速普通GEMV计算，可以提升性能2.x. 通过分析OPT模型，发现decoder阶段，模型中GEMV计算比例超过百分之六十，xxx 存在加速的可能性。找到模型中gemv计算模块，用xxx硬件接口替换torch的接口。验证性能，完成了1.5x~1.9x 的性能加速。  
* 负责量化算法研究， 分析过SqueezeLLM算法思想，并成功应用到 xxx 项目组量化仓库中，提升了大模型量化的精度。SqueezeLLM是通过海森矩阵确定模型结构中weight的敏感度，将敏感值高的weight量化为高bit, 将敏感值低的weight量化为低bit。分别用不同的tensor存储高bit和低bit的weight。此算法可以提升模型量化之后的精度，但是会带来计算上性能的下降。  
* 负责xxx项目组量化仓库的重构。为了做量化精度提升的实验，以前的量化framework集成了很多量化算法，对于framework结构没有统一的定义，xxx组成员各自按照自己的思路集成不同的量化方法。为了统一量化framwork的结构，并且易于集成新的量化算法到framwork中，重新设计了需求文档以及软件设计文档。重构了量化仓库。个人完成了其中百分之八十的工作量。重构量化framwork包含smooth， rotation，GPTQ，RTN, 以及xxx自己提出的block wise rotation，RTEC等量化功能。  
* executorch 二次开发， 2025年 xxx新的任务是将量化后的小模型运行在三*手机端，通过调研，xxx选择以ExecuTorch作为framwork，将量化仓库生成的量化后模型，加载到Executorch端，生成pte文件，在s24手机端完成推断。ExecuTorch支持w4A8量化和rotation功能。 为了适配 xxx自己的量化算法，修改ExecuTorch Llama 模型结构，增加了 rotation without fuse layerNorm 和 block wise rotation 功能。

