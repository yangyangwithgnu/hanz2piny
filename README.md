<h1 align="center">能处理姓氏异读的汉字转拼音工具：hanz2piny</h1>
yangyangwithgnu@yeah.net  
http://yangyangwithgnu.github.io/  
2016-04-12 12:58:02


##谢谢

**捐赠：支付宝 yangyangwithgnu@yeah.net ，支付宝二维码（左），微信二维码（右）**
<div align="center">
<img src="https://raw.githubusercontent.com/yangyangwithgnu/yangyangwithgnu.github.io/master/pics/alipay_donate_qr.png" alt=""/>
<img src="https://raw.githubusercontent.com/yangyangwithgnu/yangyangwithgnu.github.io/master/pics/wechat_donate_qr.png" alt=""/><br>
</div>

**二手书**：书，我提高开发技能的重要手段之一，随着职业生涯的发展，书籍也在不断增多，对我而言，一本书最多读三遍，再往后，几乎没有什么营养吸收，这部分书对我已基本无用，但对其他人可能仍有价值，所以，为合理利用资源，我决定低价出售这些书，希望达到两个目的：0）用售出的钱购买更多新书（没当过雷锋的朋友 (๑´ڡ`๑)）；1）你低价购得需要的书（虽然二手）。到 https://github.com/yangyangwithgnu/used_books 看看有无你钟意的。


##公告

**讨论**：任何意见建议 yangyangwithgnu@yeah.net  


##版本

**[v0.1.0，新增，2016-04-12]**：发布初始版本。  


##0 summary 

hanz2piny is a tool that easy convert chinese hanzi to mandarin pinyin. It fast, no-DB-file, and supports polyphone.

Some limiting condition you should keep in mind. ONE, hanz2piny just handle simplified and traditional chinese hanzi, no japan kanji, no korea hanja, and just output mandarin pinyin, no cantonese pinyin, no taiwanese pinyin; TWO, hanz2piny just handle the little-endian UTF-8 encoding file, no UTF-16 (yes, similar as your unicode), no ASCII.

If you are unix-like user, as follow steps to install hanz2piny:  
```
# 0) make sure the build tools standing by: g++ (C++11 supports), cmake, make
# 1) clone the source code: 
git clone https://github.com/yangyangwithgnu/hanz2piny.git
# 2) go into the build dir:
cd hanz2piny/build
# 3) generate make file:
cmake .
# 4) build the bin and install
make && make install
```

If you are my m$-windows lord, I DO NOT bother you to feel the building hell, so, click the "Download ZIP" button, unzip hanz2piny-master.zip, unzip hanz2piny-master\bin\prebuild_4_win.7z, then the bin-exe file hanz2piny.exe lies there, my honor! 

The usage is very simple, total eight command line options, and only one needs you set up: 
* --help. show this help info, ignore the others options;
* --version. show current version, ignore the others options except --help;
* --tone. set on that pinyin with tone;
* --camel. set on that the first letter of every pinyin in capital, I.E., camel style;
* --polyphone. some hanzi have more one pinyin, these ones I.E. polyphone. You can get all option pinyin, set up argument as all; you focus pinyin in name, set up name; you focus pinyin in non-name, set up noname. The default argument is noname;
* --replace-unknown. some char that hanz2piny could not handle, you can replace them by set on this option;
* --replace-unknown-with. some char that hanz2piny could not handle, you can replace them with string by set up this argument; 
* --path. set up the file path that chinese hanzi file, make sure the file is exist and the encoding is UTF-8. 

That's it. 


##1 缘由 

渗透测试中，我常常会优先进行密码攻击，这是各种防御体系中最容易忽略也是为害最大的脆弱面。要进行密码攻击，帐号字典和密码字典是基础；要提高密码攻击的成功率，通过社会工程学制作出具备社工特性的帐号字典和密码字典是方式之一。要对某个公司进行密码攻击（已授权的：），以公司员工姓名为基础的帐号字典，相较在互联网上找的帐号字典，肯定前者命中率高得多，这时，我需要一个工具，将所有员工中文姓名转换为对应拼音，以便后期加工成帐号字典。

网上有几个类似的项目，java 版本的 pinyin4j（http://pinyin4j.sourceforge.net/ ），python 版本的，pinyin（https://github.com/hotoo/pinyin ），对于大规模数量的中文来说，效率不够高；C 版本的 Chinese2Pinyin（https://github.com/jishipu/Chinese2Pinyin ），效率倒是不错，但无法处理姓氏异读，还得附带单独的拼音数据文件。没有满意的，自己实现一个，hanz2piny。


##2 简介

hanz2piny 是一个汉字转拼音的工具，它高效、易用、无需单独数据文件，非常适合用于制作密码攻击的帐号字典，因为 hanz2piny 能处理姓氏异读。

使用 hanz2piny 得有两个条件：一是，文件必须为小尾存储的 UTF-8 编码；二是，输入的汉字，只处理简体和繁体汉字，不处理日文汉字、韩文汉字，输出的拼音，只会是普通话拼音，不会是广东话拼音、闽南语拼音。


##3 安装

unix-like 用户，参照如下步骤进行源码构建：  
```
# 0) make sure the build tools standing by: g++ (C++11 support), cmake, make
# 1) clone the source code: 
git clone https://github.com/yangyangwithgnu/hanz2piny.git
# 2) go into the build dir:
cd hanz2piny/build
# 3) generate make file:
cmake .
# 4) build the bin and install
make && make install
```

m$-windows 亲，点击 "Download ZIP" 按钮下载, 解压后二进制可执行程序位于 hanz2piny\bin\4_win\hanz2piny.exe，使用即可。

##4 使用

hanz2piny 的完整命令行选项如下：  
--help  
显示帮助信息。该选项优先级最高，出现该选项时忽略其他所有选项；  
可选；  
无参数。  
--version  
显示当前版本信息。该选项优先级仅次于 –help；  
可选；  
无参数。  
--tone  
指定拼音带声调。若指定该选项则返回带声调的拼音，反之则不带；  
可选；  
无参数。  
--camel  
指定拼音首字母大写（即，驼峰风格）显示；  
可选；  
无参数。  
--polyphone  
指定多音字转换方式。all，返回多音字的所有拼音，两侧用 <> 包裹、中间用 , 分割；name，返回多音字用于姓氏的拼音；noname，返回多音字用于非姓氏的拼音；  
可选；  
参数列表：all、name、noname；  
默认参数：noname。  
--replace-unknown  
指定输出结果中，替换掉未成功转换拼音的原字符；  
可选；  
无参数。  
--ignore-utf8-check
跳过文件的utf8合法行检查
可选； 默认开启检查 
无参数。  
--replace-unknown-with  
输出结果中，用指定的字符串替换掉未成功转换拼音的原字符。若未指定 --replace-unknown，则即便指定 --replace-unknown-with 也无效果；  
可选；  
参数列表：任何字符串。  
--path  
指定待转换为拼音的文件路径，该文件必须为小尾存储的 UTF-8 编码；  
必选；  
参数列表：任何小尾存储的 UTF-8 编码的有效文本文件路径。

hanz2piny 是个命令行程序，要用好它，你得先了解几个命令行选项的常识：  
* --option 'argc'，其中，--option 称之为命令行选项，argc 为命令行参数；
* 某些命令行参数中可能含有对 shell 有特殊含义的字符（如，home/ 目录缩写的 ~、后台运行的 &、用于分割符的空格），为避免 shell 误解，通常，应该用英文单引号包裹命令行参数。如，--replace-unknown-with '~'；
* 某些命令行选项可以有多个参数，通常，每个参数单独用英文单引号包裹，参数间用空格分割。如，--album '八度空间' '范特西' '我很忙'；

hanz2piny 虽然有八个命令行选项，但只有 --path 这个参数需要手工指定，其它均有默认参数。举个例子，有个待转换拼音的文件位于 /data/workplace/hanz2piny/test_txt/linux/pentest.txt，内容为
```
    渗透测试(penetration test)并没有一个标准的定义，国外一些安全组织达成共识的通用说法是：渗透测试是通过模拟恶意黑客的攻击方法，来评估计算机网络系统安全的一种评估方法。这个过程包括对系统的任何弱点、技术缺陷或漏洞的主动分析，这个分析是从一个攻击者可能存在的位置来进行的，并且从这个位置有条件主动利用安全漏洞。

    换句话来说，渗透测试是指渗透人员在不同的位置（比如从内网、从外网等位置）利用各种手段对某个特定网络进行测试，以期发现和挖掘系统中存在的漏洞，然后输出渗透测试报告，并提交给网络所有者。网络所有者根据渗透人员提供的渗透测试报告，可以清晰知晓系统中存在的安全隐患和问题。

    我们认为渗透测试还具有的两个显著特点是：渗透测试是一个渐进的并且逐步深入的过程。渗透测试是选择不影响业务系统正常运行的攻击方法进行的测试。作为网络安全防范的一种新技术，对于网络安全组织具有实际应用价值。但要找到一家合适的公司实施渗透测试并不容易。

    渗透人员：仇小兵、朴槿惠、单伟、缪小军、区华、曾祥洪。(ง •̀_•́)ง
```

前面提过，hanz2piny 只处理小尾存储的 UTF-8 编码的文件，如果不满足，hanz2piny 会提示：  
```
ERROR! fail to open UTF-8 encoding file /data/workplace/hanz2piny/test_txt/linux/UTF16.txt. make sure the file is exist and the encoding is UTF-8.
```
其他编码的文件要转成小尾存储的 UTF-8 编码的文件很容易。unix-like 用户，可以先执行  
```
file --mime-encoding utf-16be_file.txt
```
查看文件的编码格式以及小尾还是大尾存储；然后将原编码格式（下例中的 utf-16be）作为 -f 选项的参数，执行  
```
iconv -f utf-16be -t utf-8 utf-16be_file.txt > UTF-8_file.txt
```
这样，轻松将大尾存储的 UTF-16 编码的文件 utf-16be\_file.txt 转换成小尾存储的 UTF-8 编码格式的文件 UTF-8_file.txt。m$-windows 用户，用记事本打开原文件，菜单项依次选择打开 – 另存为，在"编码"下拉列表中选择 UTF-8，保存即可。

满足了基本条件，汉字转拼音，默认情况下只需指定 --path 即可：  
```
hanz2piny --path '/data/workplace/hanz2piny/test_txt/linux/pentest.txt'
```
结果如下：
<div align="center">
<img src="https://github.com/yangyangwithgnu/hanz2piny/blob/master/doc/pics/%E9%BB%98%E8%AE%A4%E8%BD%AC%E6%8D%A2.jpg" alt=""/><br />
（默认转换）
</div>
可以看到，hanz2piny 将所有简体汉字全转换为拼音，并保留了原文格式（如，段落格式、段首的空白字符）。

拼音是有了，如果需要声调，设置 --tone 即可：
```
hanz2piny --path '/data/workplace/hanz2piny/test_txt/linux/pentest.txt' --tone
```
结果如下：
<div align="center">
<img src="https://github.com/yangyangwithgnu/hanz2piny/blob/master/doc/pics/%E6%98%BE%E7%A4%BA%E5%A3%B0%E8%B0%83.jpg" alt=""/><br />
（显示声调）
</div>

原文中最后一段是几个含有多音字的人名（如，仇小兵），hanz2piny 转换结果（如，chou2xiao3bing1）有误，这就需要通过 --polyphone 告诉 hanz2piny 应如何处理多音字，三个参数：name 为姓氏拼音、noname 为非姓氏拼音、all 为该多音字的所有拼音。比如，需要优先处理姓氏异读，指定 --polyphone name 即可：
```
hanz2piny --path '/data/workplace/hanz2piny/test_txt/linux/pentest.txt' --tone --polyphone name
```
结果如下：
<div align="center">
<img src="https://github.com/yangyangwithgnu/hanz2piny/blob/master/doc/pics/%E5%A7%93%E6%B0%8F%E5%BC%82%E8%AF%BB.jpg" alt=""/><br />
（姓氏异读）
</div>

如果觉得密密麻麻的拼音不容易分开，可以指定 --camel 让拼音以驼峰风格显示：
```
hanz2piny --path '/data/workplace/hanz2piny/test_txt/linux/pentest.txt' --tone --polyphone name --camel
```
结果如下：
<div align="center">
<img src="https://github.com/yangyangwithgnu/hanz2piny/blob/master/doc/pics/%E9%A9%BC%E5%B3%B0%E9%A3%8E%E6%A0%BC.jpg" alt=""/><br />
（驼峰风格）
</div>

对于无法转换的字符（如，英文单词、中文标点符号），可以用指定的字符串进行替换。--replace-unknown 设置需要替换，--replace-unknown-with 指定具体替换内容：
```
hanz2piny --path '/data/workplace/hanz2piny/test_txt/linux/pentest.txt' --tone --polyphone name --camel --replace-unknown --replace-unknown-with '*'
```
结果如下：
<div align="center">
<img src="https://github.com/yangyangwithgnu/hanz2piny/blob/master/doc/pics/%E6%9B%BF%E6%8D%A2%E6%97%A0%E6%B3%95%E8%BD%AC%E6%8D%A2%E7%9A%84%E5%AD%97%E7%AC%A6.jpg" alt=""/><br />
（替换无法转换的字符）
</div>

你可能觉得既 --replace-unknown 设置是否替换，又用 --replace-unknown-with 指定具体替换内容会很繁冗，不如只保留 --replace-unknown-with，当指定空字符串时不替换、非空时用指定的字符串进行替换。实际上，这是不行的，比如，我需要在输出结果中不保留任何无法转换成拼音的字符，这时，后者方式是无法达到这一目的的，只能：
```
hanz2piny --path '/data/workplace/hanz2piny/test_txt/linux/pentest.txt' --tone --polyphone name --camel --replace-unknown --replace-unknown-with ''
```
结果如下：
<div align="center">
<img src="https://github.com/yangyangwithgnu/hanz2piny/blob/master/doc/pics/%E4%B8%8D%E4%BF%9D%E7%95%99%E6%97%A0%E6%B3%95%E8%BD%AC%E6%8D%A2%E7%9A%84%E5%AD%97%E7%AC%A6.jpg" alt=""/><br />
（不保留无法转换的字符）
</div>


##5 FQA

Q0：我是 m$-windows 用户，双击 hanz2piny.exe 后，命令行窗口一闪而过，无法指定命令行选项？  
A0：既然是命令行程序，通常应在命令行中启动，而不是双击启动。你可以先在文件管理器中进入 hanz2piny.exe 所在目录，接着键入 alt-d 将光标定位到文件管理器的地址栏中，然后键入 CMD 回车在该目录下打开命令行窗口，最后在命令行窗口中键入 hanz2piny.exe 即可启用该程序。

Q1：hanz2piny 能处理所有简体、繁体中文汉字么？  
A0：不能。hanz2piny 只处理 UCS2 序号（数值上等同于 unicode）在 [4E00, 9FA5] 区间的 20902 个汉字，常见简体、繁体汉字都在里面，够用了。


##6 开发

hanz2piny 的整个开发过程很平顺，思路也很清晰，大致说下我认为重要的几点。

要将汉字转换为拼音，最直观的想法是创建汉字-拼音的映射表，根据汉字查找对应拼音即可。这种方式对我而言有两个问题：一是收集大量汉字和拼音太耗精力，二是程序中加载大量汉字和拼音太耗空间。换个思路，计算机能存放不同汉字，那么肯定每个汉字有唯一序号，如果这些序号是连续的，那么程序只需加载按序号的顺序加载不同拼音，这样极大的节约了空间。比如，"一"的序号是 0、"丁"的序号是 1、"丂"的序号是 2、"七"的序号是 3，程序只需依次将对应拼音 yi、ding、kao、qi 加载进顺序容器（如，数组）中，逻辑上，程序把输入的汉字转换为序号，序号适当处理后可成为顺序容器的下标，这样轻松找到该汉字对应的拼音。按这个思路，找到一种用于表示不同汉字的唯一、连续、有序的序号表是关键，unicode，正是我需要的（严格来说，是 UCS-2）。

###6.1 序号表

关于 unicode，大家存在很多误解，有必要这里认真说明下。

最早，老美制定了 ANSI 编码标准，一个编码占 8 位，最多能容纳 128（2^7，最高位保留给硬件设备商使用）个字符，这对于英文字符够用了，但欧洲、亚洲等地区来说完全不够用，后来，有个国际委员会希望编制一种新标准，能容纳世界上所有字符，这就是 unicode。

**unicode 只是一个愿景**，没有任何实质东西。为了让 unicode 落地，委员会制定了 unicode 的**序号表 UCS-2**，占 16 位，最多能容纳 65536（2^16）个字符，每个字符有各自唯一的序号（但不是编码）；后来发现还是不够，又发展出另一套**序号表 UCS-4**，占 32 位，最多能容纳 42,9496,7296（2^32）个字符。按理说，UCS-4 已经能够容纳下这个星球上所有字符了，每个字符又有唯一序号，那么直接用该序号表作为编码就可以了，但是，不是每个国家的每台计算机都需要显示全量字符（比如，我的机器上并未安装藏文字符，因为我根本不认识藏文，也确定不会使用或者阅读任何藏文的软件或者文章），只要合理划分了区域，真正用得到的那部分字符集只需 16 位就够了，强制使用 UCS-4 的 32 位就太浪费了，所以，又发明了将序号表 UCS 映射为**编码集 UTF**，一种变长编码格式。最终，在计算机中落地的、唯一表示某个字符的编码集就是 UTF。

UTF 目前有三个版本：UTF-8、UTF-16、UTF-32。UTF-8 编码是变长的，最少占用 1 个字节，最多占用 6 个字节；UTF-16 编码是定长的，占用 2 个字节；UTF-32 也是定长的，占用 4 个字节。从存储资源使用率高、容纳字符范围广的角度来看，UTF-8 最优，所以，UTF-8 是目前广泛采纳的编码格式。

有了以上信息，unicode 与 UTF 关系的问题就很清晰了。unicode 是愿景、UCS 是 unicode 的序号表、UTF 是 UCS 的编码集。unicode 没有任何实质东西，谈不上与 UTF 的转换，真正能转换的是 UCS 与 UTF。UTF-16 与 UCS-2 一一对应，UTF-32 与 UCS-4 一一对应，所以，这两对不用转换，本来数值上就相等；而 UTF-8 是变长的，UTF-8 与 UCS-2 的转换必须基于具体规则。

由于混用 unicode、UCS-2、UTF-16 三者的情况非常普遍（不乏知名书籍、软件），为兼顾，我只能"继续错下去"，但是你心里一定得明了：unicode、UCS-2、UTF-16，三者在数值上相同，三者在概念上差异万千。m$-windows 的记事本是个典型例子：
<div align="center">
<img src="https://github.com/yangyangwithgnu/hanz2piny/blob/master/doc/pics/%E8%AE%B0%E4%BA%8B%E6%9C%AC%E6%B7%B7%E6%B7%86%20unicode%20%E4%B8%8E%20UTF-16.jpg" alt=""/><br />
（记事本混淆 unicode 与 UTF-16）
</div>

好了，现在，我需要找到一份序号-拼音的对应表。http://kanji.zinbun.kyoto-u.ac.jp/~yasuoka/ftp/CJKtable/Uni2Pinyin.Z （看，又一个把 unicode 与 UCS-2 搞混淆的例子，严谨的命名应该是 Ucs2Pinyin.Z ）是我要的。该对应表包含两列信息，前列为 UCS-2 序号、后列为拼音（多音字对应多个拼音）。文档位于 hanz2piny/refer/Uni2Pinyin，大致如下：
<div align="center">
<img src="https://github.com/yangyangwithgnu/hanz2piny/blob/master/doc/pics/%E5%BA%8F%E5%8F%B7-%E6%8B%BC%E9%9F%B3%E5%AF%B9%E5%BA%94%E8%A1%A8.jpg" alt=""/><br />
（序号-拼音对应表）
</div>
按前面说的，我提取拼音一列放入程序代码中，保留拼音前后顺序。

同时，hanz2piny 要处理姓氏异读问题，我需要参见异读姓氏的拼音列表，主要参考了 http://tieba.baidu.com/p/1816379737 和 http://bbs.tianya.cn/post-books-181959-1.shtml 。文档位于 hanz2piny/refer/polyphone\_in_name，大致如下：
<div align="center">
<img src="https://github.com/yangyangwithgnu/hanz2piny/blob/master/doc/pics/%E5%A7%93%E6%B0%8F%E5%BC%82%E8%AF%BB%E5%8F%82%E8%80%83.jpg" alt=""/><br />
（姓氏异读参考）
</div>
一般来说，姓氏异读的汉字为多音字，对应多个拼音，为便于程序处理，我将异读拼音放在该多音字对应多个拼音的位首。

###6.2 UTF-8 转 UCS-2

文件的编码格式很多，UTF-8、UTF-16、UTF-32、ASCI 等，再考虑小尾端和大尾端问题，那么程序就需要识别太多编码格式，为了减弱复杂性，hanz2piny 只处理小尾端 UTF-8 编码的文件。

好了，输入是 UTF-8，程序采用的是 UCS-2 序号表顺序的拼音，所以，需要将 UTF-8 转为 UCS-2。前面提过，unicode、UCS-2、UTF-16 三者混用的情况很常见，所以，在很多解决方案中写到：（最常见的是）UTF-8 转 unicode，或者，（其次常见）UTF-8 转 UTF-16，或者，（最少见但最严谨）UTF-8 转 UCS-2。

对于 UTF-8 转 unicode/UTF-16/UCS-2 我考虑了多种方案：STL 的 codecvt、boost 的 conv、iconv、miniutf（https://github.com/dropbox/miniutf ）、utfcpp（https://github.com/nemtrif/utfcpp ）。从使用便利、程序体积等方面考量，最终选用 utfcpp。

utfcpp 将 UTF-8 转为 UCS-2 的接口为
```
template <typename u16bit_iterator, typename octet_iterator>
u16bit_iterator utf8to16 (octet_iterator start, octet_iterator end, u16bit_iterator result);
```
看，又一个把 unicode 与 UCS-2 搞混淆的例子，严谨的命名应该是 utf8toucs2()。

###6.3 libhanz2piny 接口

我把 hanz2piny 的核心能力抽象至 /src/lib/self/libhanz2piny 中，它是个很简单的类，有需要，你可以直接放至自己项目中复用。

接口简述如下：  
```
// 只处理 unicode 在 [0X4E00, 0X9FA5] 间的汉字，检查是否在此区间。
bool
Hanz2Piny::isHanziUnicode (const Unicode unicode) const;

// 基于 unicode 查找对应汉字的拼音，若为多音字则可能返回多个拼音
vector<string>
Hanz2Piny::toPinyinFromUnicode (const Unicode hanzi_unicode, const bool with_tone) const;

// 检查字符序列是否为 UTF-8 编码格式
bool
Hanz2Piny::isUtf8 (const string& s) const;

// 基于 UTF-8 查找对应汉字的拼音。
// s 为 UTF-8 编码的字符序列，可以包含多个汉字。处理完每个汉字后，返回
// pair<bool, vector<string>>，first 表示该汉字是否成功转换拼音，second
// 该汉字具体转换的拼音列表（多音字）。
// 非汉字不作任何修改，原样返回。
vector<pair<bool, vector<string>>>
Hanz2Piny::toPinyinFromUtf8 ( const std::string& s,
                              const bool with_tone,
                              const bool replace_unknown,
                              const std::string& replace_unknown_with ) const;

// 检查指定文件是否为 UTF-8 编码
bool
Hanz2Piny::isUtf8File(const string& file_path) const;

// 检查指定字符序列是否以 BOMC 打头
bool
Hanz2Piny::isStartWithBom (const string& s) const;
```

另外，最早我把完整拼音列表放入 vector\<vector\<string>> 中，类似  
```
const vector<vector<string>> Hanz2Piny::pinyin_list_list_with_tone_ {
	{"ding1"},
	{"kao3"},
	{"qi1"},
	{"shang4", "shang3"},
	// ....
};
```
当拼音规模在几百个时，编译速度也就几十秒，还能接受，后来添加完全量 2W 个拼音时，等了几十分钟还没编译完成，估计是编译器实施优化，将 2W 个字面常量字符串提前放入 vector\<vector\<string>> 的私有数据成员中。有两个办法可以缩短编译时间，一是采用 debug 模式编译，二是弃用 vector<>。对于前者，实际上就是禁止一切优化，编译时间缩短至一分钟左右，但可执行文件体积膨胀至 16M，借助 UPX 倒是可以压缩至 2M，但始终不够优雅。对于后者，将 vector<> 改为 const char* list[]，虽然代码逻辑略微麻烦，但效果显著，几秒便可编译完成。如下：  
```
const char* Hanz2Piny::pinyin_list_with_tone_[] {
	"ding1", 
	"kao3", 
	"shang4 shang3", 
	"xia4", 
	// ....
};
```

