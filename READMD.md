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
* 负责量化算法研究， 分析过SqueezeLLM算法思想，并成功应用到 xxx 项目组量化仓库中，提升了大模型量化的精度。SqueezeLLM是通过海森矩阵确定模型结构中weight的敏感度，将敏感值高的weight量化为高bit或者不量化, 将敏感值低的weight量化为低bit。分别用不同的tensor存储高bit和低bit的weight。此算法可以提升模型量化之后的精度，但是会带来计算上性能的下降。
* 负责xxx项目组量化仓库的重构。为了做量化精度提升的实验，以前的量化framework集成了很多量化算法，对于framework结构没有统一的定义，xxx组成员各自按照自己的思路集成不同的量化方法。为了统一量化framwork的结构，并且易于集成新的量化算法到framwork中，重新设计了需求文档以及软件设计文档。重构了量化仓库。个人完成了其中百分之八十的工作量。重构量化framwork包含smooth， rotation，GPTQ，RTN, 以及xxx自己提出的block wise rotation，RTEC(round and Truncation error compensation)等量化功能。完成了量化后weight 压缩功能，用uint32数据而机构存储量化后的weight。（如一个uint32 存储4个int8 数据类型，或者一个uint32 存储八个int4 数据）。   
* executorch 二次开发， 2025年 xxx新的任务是将量化后的小模型运行在三*手机端，通过调研，xxx选择以ExecuTorch作为framwork，将量化仓库生成的量化后模型，加载到Executorch端，生成pte文件，在s24手机端完成推断。ExecuTorch支持w4A8量化和rotation功能。 为了适配 xxx自己的量化算法，修改ExecuTorch Llama 模型结构，增加了 rotation without fuse layerNorm 和 block wise rotation 功能。

专业技能：  
掌握 c， c++, python 等编程语言。  
熟悉 transformer decoder 类型模型结构以及这些模型推理过程，如OPT， llama等。  
熟悉 llm的profile方法，通过torch.profile 以及nsight system 等工具研究模型推理性能， 找出模型推断的瓶颈等。   
熟悉 pytorch 框架，有丰富的模型推理以及部署经验。  
项目经验  
**OPT模型分析以及推理加速**  
* 背景
    + 近年来，Large Language Model(LLM)发展很快，是未来学术界以及科技界发展的主流趋势,LLM的训练成本高，对于软硬件要求较高，普通公司很难有机会在模型训练上有所成就。但是大模型推断相对简单，san *公司认为在大模型推断领域，xx硬件可能会有很大的加速空间，所以我们需要调研大模型结构以及推理过程，集成xxx完成加速。 
*思路  
    + xxx的特征是可以对GEMV操作加速，主要原理是在xxx中添加算子，减少数据从内存搬移到累加器的时间。针对这个特征，我们需要分析大模型的结构，找出GEMV操作计算的模块，调用。。。接口完成计算。首先使用torch.profile 和 nsightSystem 工具去分析模型中的算子，以及占比。通过分析多个模型，发现OPT模型 batch size =1时， 在模型decoder阶段， gemv 操作占比较多，gemv操作主要集中在模型attention 中的create q_proj, k_proj，v_proj, o_proj, 以及MLP中的 gate_proj,up_proj, down_proj 中torch.nn.linear计算中。在模型结构中调用torch.nn.linear部分调用xxx 计算接口，最终完成xxx硬件加速 LLM的任务，加速比可达 1.5x
    + 中间还分析过 fasterTransformer比 pytorch推断时间 快的原因，主要是kernel fusion
    + AMD 显卡支持问题等 以及TP,PP 等问题
    + DP 数据并行 每个服务器单独处理各自数据，最后有需要的时候汇总。
    + TP 模型并行 将大的tensor切分为小的tensor，放在不同GPU，每个GPU算结果的不同部分，最后累加得到结果。
    + PP 流水线并行 将大模型不同层放在不同的服务器上，每个层即服务器的输出是下一个服务器的输入。
    + 分析过nccl 源码， 为了找出 deepspeed 多卡TP 过程中， 通信时间较长的原因。
  
**重构量化framwork 结构设计。**  
* 背景  
   + 为了更加方便的完成最新量化算法的研究以及实验，需要对旧版本的量化仓库进行重构，完成模型量化后的精度要求。
  
* 思路
  + 设计framwork的结构，主要包含profile，Quantization，evaluation三大模块，profile是在量化之前抓取模型数据的特征，以便在量化的时候直接使用，包含对于weight和激活量化特征的提取。量化是模型weight 量化的具体实现，主流方法有RTN和GPTQ.量化后模型需要通过评估函数即 evaluation模块完成量化精度的评估，目前主流方法是GPTQ evaluation 和 lm_eval_harness.对于量化模块，通过Python 注册机制设计，将不同量化算法封装成一个类，入参是模型，校验数据集等，通过循环遍历，完成不同算法的组合执行。  

**SqueezeLLM 算法研究**  
* 背景  
   + 验证Sqeezellm 量化算法的精度。
* 思路
   + 研究论文，看懂SqeezeLLM的方法和原理。SqeezeLLM是将普通weight分成 dense和sparse tensor, 其中sparse tensor 包含两部分值，0.4%的离群值和0.05%的敏感值（敏感值来自于海森矩阵算法）， 剩余的weight 属于dense tensor，对于sparse tensor 保持高精度，不参与量化（没有量化损失）， 对于dense tensor进行常规量化。通过这种方法提升量化的精度。将论文代码实现在了量化framwork中，并复现了论文中的精度。同时为了探究离群值和 敏感值对模型精度的影响，做了很多对比实验。此方法可以提升精度，但是没法解决性能以及存储问题，会增加额外的计算和存储空间。

**cutlass kernel的修改以及调用。**     
* 背景
   + xxx 自己提出了舍入截断误差补偿的方法（round and Truncation error compensation:RTEC）提升模型量化精度，此方法是在量化模型过程中，保存模型量化时候的舍入误差和截断误差（对于模型wieght,为了不引入大量的内存开销，只保留1% channel的误差，选择标准是离群值的占比）对于模型精度提升很有效果，但是会引入额外的计算。此方法要求稀疏tensor计算。
* 思路

    41/4096                             4096          4096   
    x x √ x x ....           X    41           =             2048    
  并修改cutlasskernel实现。
   
**模型量化之后，压缩保存算法研究。**
* 背景
   + 在模型量化之后，我们需要保存模型weight，变成语言（如Python）不支持int4 数据类型，一般情况下int4数据是保存在FP16数据结构中，这样实际量化后模型大小和原始模型大小几乎没有变化，急需研究方法保存int4数据。
* 思路
  + 通过调研其他framwork的数据存储方式，选用uint32存储量化后的int4或者int8数据。即一个uint32存储8个int4,或者一个uint32存储4个int8的数据。设计了量化后模型压缩过程，并通过Python 基本操作（移位， 与或非等）完成量化后数据的存储。
** quad Tree 压缩算法实现 **
* 背景
   + xxx 有新的调研需求，研究 这个算法压缩量化后模型的压缩比。
* 思路
   + 将一个大的tensor 通过四分法，分成四部分，（通过树结构实现）对于每一部分继续分成四部分，直到满足两个条件停止 1） 所有块都是相同的值，这样的话，每个树节点只存储一个值，2）分到只剩一个元素， 记录此节点的值。通过Python代码，实现了完成了压缩流程。但是压缩效果不及预期，分析原因，主要是 weight量化后，值的分布没有规律，不满足局部相思相的特点。而对于图像压缩，由于满足局部相似性的特征， 此算法压缩比很高。
   + 

  
   
