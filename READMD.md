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
* 负责xxx项目组量化仓库的重构。为了做量化精度提升的实验，以前的量化framework集成了很多量化算法，对于framework结构没有统一的定义，xxx组成员各自按照自己的思路集成不同的量化方法。为了统一量化framwork的结构，并且易于集成新的量化算法到framwork中，重新设计了需求文档以及软件设计文档。重构了量化仓库。个人完成了其中百分之八十的工作量。重构量化framwork包含smooth， rotation，GPTQ，RTN, 以及xxx自己提出的block wise rotation，RTEC(round and Truncation error compensation)等量化功能。完成了量化后weight 压缩功能，用uint32数据而机构存储量化后的weight。（如一个uint32 存储4个int8 数据类型，或者一个uint32 存储八个int4 数据）。   
* executorch 二次开发， 2025年 xxx新的任务是将量化后的小模型运行在三*手机端，通过调研，xxx选择以ExecuTorch作为framwork，将量化仓库生成的量化后模型，加载到Executorch端，生成pte文件，在s24手机端完成推断。ExecuTorch支持w4A8量化和rotation功能。 为了适配 xxx自己的量化算法，修改ExecuTorch Llama 模型结构，增加了 rotation without fuse layerNorm 和 block wise rotation 功能。

专业技能：  
掌握 c， c++, python 等编程语言。  
熟悉 transformer decoder 类型模型结构以及这些模型推理过程，如OPT， llama等。  
熟悉 llm的profile方法，通过torch.profile 以及nsight system 等工具研究模型推理性能， 找出模型推断的瓶颈等。   
熟悉 pytorch 框架，有丰富的模型推理以及部署经验。  
项目经验  
OPT模型分析以及推理加速  
* 背景
    + 近年来，Large Language Model(LLM)发展很快，是未来学术界以及科技界发展的主流趋势,LLM的训练成本高，对于软硬件要求较高，普通公司很难有机会在模型训练上有所成就。但是大模型推断相对简单，san *公司认为在大模型推断领域，xx硬件可能会有很大的加速空间，所以我们需要调研大模型结构以及推理过程，集成xxx完成加速。 
*思路  
    + xxx的特征是可以对GEMV操作加速，主要原理是在xxx中添加算子，减少数据从内存搬移到累加器的时间。针对这个特征，我们需要分析大模型的结构，找出GEMV操作计算的模块，调用。。。接口完成计算。首先使用torch.profile 和 nsightSystem 工具去分析模型中的算子，以及占比。通过分析多个模型，发现OPT模型gemv 操作占比较多，gemv操作主要集中在模型attention 中的create q_proj, k_proj，v_proj, o_proj, 以及MLP中的 gate_proj,up_proj, down_proj 中linear的操作中。
  
量化算法研究 RTEC功能的实现以及底层 int4kernel的调用。  
模型量化之后，压缩保存算法研究。  
重构量化framwork 结构设计。  


