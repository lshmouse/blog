---
layout: post
title: "introduction to ARM"
description: ""
category: 
tags: []
---
{% include JB/setup %}

最近复习计算机体系结构里面指令集架构时，想以ARM为例，了解指令集的设计。
先科普一下ARM外围的一些知识。

ARM公司的模式
================
ARM(Advanced RISC Machine) 负责指令集设计，没有具体电路
芯片公司：从ARM公司买授权，生产ARM兼容的芯片。在和其他芯片打包集成，卖给硬件厂商。

如小米3使用高通的SnapDragon800的芯片，包含krait 400 cpu, Adreno 330的图像芯片，
调制解调芯片（处理手机芯片的）等等。而krait 400是ARMv7 兼容芯片。

参考： http://en.wikipedia.org/wiki/ARM_architecture

ARM公司的ARM芯片内核分类
=========================
Cortex-A  Cortex-R Cortex-M
A: Application 智能手机，移动计算平台，数字电视等
R: Realtime 工业控制，数字电视
M: Microcontrollers 智能测量、人机接口设备、汽车和工业控制系统
参考： http://hi.baidu.com/xuelicheng/item/b896b7d1b7583848fb5768d0
