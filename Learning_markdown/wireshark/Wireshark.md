# This is a WireShark Markdown
## wireshark search op
### 查找地址
||||
|-|-|-|
|eth.|   addr/dst/src|==
|ip. |    addr/dst/src|==
### 过滤端口
||||
|-|-|-|
|tcp.<br> udp.  | port | ==  <br> <= <br>  >= |

### 过滤协议
输入协议就行
不想要可以用
！协议


### 包长度过滤
|||
|-|-|
|udp.length ==??|长度是udp固定8加数据包
|tcp.len ==??|ip数据包长度，不包括tcp
|ip.len==?|除去以太网固定长度14，剩下都是ip.len,就是ip自己本身|
|frame.len|整个数据包长度|

eth —> ip or arp —> tcp or udp —> data

### http模式过滤
http.request.method == "GET"
http.request.method=="POST"
http.request.uri== "/img/logo-edu.gif"
http contains "GET"
http contains "HTTP/1."

request.method $~~~~~~~$可以筛选到该报文的模式，这个信息也在info中也可以通过contains获取
request.uri  $~~~~~~~$查找uri
contains $~~~~~~~$具体看info信息

### tcp参数过滤
tcp.flags  $~~~~~~~$ 显示有tcp标志的包
tcp.flags.syn==0x02 显示有tcp syn的包
tcp.window_size ==0  窗口大小
tcp.flags.reset!=1 不重置


### dns
dns.qry.name == "域名"
dns.qry.type ==1 a记录查询


### DHCP

bootp


### msn
msnms && tcp[23:1]==20 第四个是0x20的msn数据包
如何判断MSN数据包是否含有命令编码
1）端口为1863或者80 
2）数据这段前三个是大写字母20~22是41~5A(asii的十六进制)
3） 第四个是0x20
4） msn属于TCP


1. 捕获过滤器（Capture Filter）详解
捕获过滤器作用是在抓包开始前限制抓取数据包，基于BPF（Berkeley Packet Filter）语法。它对数据流量起“网筛”作用，过滤掉不关心的包，节省空间和性能。常用在抓包前预过滤。

1.1 基础语法结构

捕获过滤器是基于简洁的关键词和运算符，形式类似：

<表达式> [and|or|not <表达式>] ...

支持的基本关键词：


1.2 逻辑运算符

and：且
or：或
not：非
示例：

抓取源IP是10.0.0.1且目标端口为80的TCP流量：

src host 10.0.0.1 and tcp and dst port 80
抓取所有UDP包或ICMP包：

udp or icmp
排除ARP包：

not arp
1.3 捕获过滤器示例



2. 显示过滤器（Display Filter）详解
显示过滤器用在抓包完成后筛选数据包，功能强大、语法复杂，能针对各种协议和字段精确过滤。

2.1 语法结构

<协议>.<字段> <比较符> <值> [逻辑运算符 <过滤表达式>]...

2.2 常用比较符


2.3 逻辑运算符

and：且
or：或
not：非
2.4 常用协议及字段示例


2.5 示例过滤器

过滤源IP是10.0.0.2的包：

ip.src == 10.0.0.2
过滤目标端口是80或443的TCP包：

tcp.dstport == 80 or tcp.dstport == 443
过滤HTTP GET请求：

http.request.method == "GET"
过滤DNS查询包：

dns.flags.response == 0


3. 显示过滤器高级技巧
3.1 组合逻辑过滤

过滤条件可以任意组合，利用括号明确优先级，满足复杂过滤需求。

示例：过滤源IP是192.168.1.1且目标端口是80或443的TCP包

ip.src == 192.168.1.1 and (tcp.dstport == 80 or tcp.dstport == 443)

3.2 利用协议标志位过滤

针对TCP标志位的过滤非常实用，常用于诊断连接问题。

过滤TCP SYN包（发起连接）

tcp.flags.syn == 1 and tcp.flags.ack == 0
过滤TCP FIN包（关闭连接）

tcp.flags.fin == 1
过滤TCP重传包

tcp.analysis.retransmission
3.3 按报文长度过滤

有时候抓包数据量巨大，可以按包大小过滤，只看超过一定长度的包。

frame.len > 1000

这可以帮你快速聚焦大数据包，比如文件传输。

3.4 过滤存在某字段的包

某些字段只有部分包有，例如SSL握手包中的ssl.handshake字段，过滤时可以用：

ssl.handshake

表示只显示带有握手字段的包。

3.5 过滤IPv6流量

IPv6过滤与IPv4类似，但字段名不同。

过滤IPv6源地址为fe80::1的包：

ipv6.src == fe80::1
过滤所有IPv6流量：

ipv6
3.6 过滤字符串字段包含关系

常用HTTP或DNS过滤，查找域名或URL包含某关键字。

HTTP Host中包含google：

http.host contains "google"
DNS查询名匹配某正则表达式（如所有以.com结尾）：

dns.qry.name matches ".*\.com"


4. 捕获过滤器实用技巧和复杂表达式
4.1 捕获时指定多个条件

要捕获多个IP或端口流量时，用括号明确优先级。

示例：抓取目的IP是192.168.1.1或192.168.1.2的TCP包

tcp and (dst host 192.168.1.1 or dst host 192.168.1.2)

4.2 排除特定协议

想抓包排除ARP包：

not arp

想抓取非TCP包：

not tcp

4.3 指定网卡的捕获过滤器

用-i参数指定抓哪个接口，结合过滤器精确抓包：

tcpdump -i eth0 tcp port 80

4.4 捕获过滤器语法限制

捕获过滤器不支持协议内部字段，只能针对包头基本字段（IP、端口、协议），不支持显示过滤器的复杂条件。



5. 显示过滤器常见字段详细解析（部分）


6. 显示过滤器更详细字段解析
6.1 以太网层（Ethernet）

eth.src：源MAC地址
eth.dst：目的MAC地址
eth.type：以太网类型，如0x0800表示IPv4，0x86DD表示IPv6
6.2 IP层

ip.version：IP协议版本，4或6
ip.ttl：生存时间（TTL）
ip.id：标识，用于分片识别
ip.proto：承载协议类型，如6是TCP，17是UDP
ip.flags：分片标志
ip.frag_offset：分片偏移
示例过滤TTL小于64的包：

ip.ttl < 64

6.3 TCP层

tcp.seq：序列号
tcp.ack：确认号
tcp.flags：标志位整体
tcp.flags.syn：同步标志
tcp.flags.ack：确认标志
tcp.flags.fin：关闭连接标志
tcp.window_size：窗口大小
过滤TCP窗口大小小于1024的包：

tcp.window_size < 1024

6.4 UDP层

udp.length：UDP报文长度
6.5 ICMP层

icmp.type：类型码（如8是Echo请求，0是Echo应答）
icmp.code：类型细分



类型TYPE	代码CODE	用途|描述 Description	查询类Query	差错类Error
0	0	Echo Reply——回显应答（Ping应答）	x	 
3	0	Network Unreachable——网络不可达	 	x
3	1	Host Unreachable——主机不可达	
x
3	2	Protocol Unreachable——协议不可达	 	x
3	3	Port Unreachable——端口不可达	
x
3	4	Fragmentation needed but no frag. bit set——需要进行分片但设置不分片比特	
x
3	5	Source routing failed——源站选路失败	 	x
3	6	Destination network unknown——目的网络未知	 	x
3	7	Destination host unknown——目的主机未知	 	x
3	8	Source host isolated (obsolete)——源主机被隔离（作废不用）	 	x
3	9	Destination network administratively prohibited——目的网络被强制禁止	 	x
3	10	Destination host administratively prohibited——目的主机被强制禁止	 	x
3	11	Network unreachable for TOS——由于服务类型TOS，网络不可达	 	x
3	12	Host unreachable for TOS——由于服务类型TOS，主机不可达	 	x
3	13	Communication administratively prohibited by filtering——由于过滤，通信被强制禁止	
x
3	14	Host precedence violation——主机越权	 	x
3	15	Precedence cutoff in effect——优先中止生效	 	x
4	0	Source quench——源端被关闭（基本流控制）	 	 
5	0	Redirect for network——对网络重定向	 	 
5	1	Redirect for host——对主机重定向	 	 
5	2	Redirect for TOS and network——对服务类型和网络重定向	 	 
5	3	Redirect for TOS and host——对服务类型和主机重定向	 	 
8	0	Echo request——回显请求（Ping请求）	x	 
9	0	Router advertisement——路由器通告	 	 
10	0	Route solicitation——路由器请求	 	 
11	0	TTL equals 0 during transit——传输期间生存时间为0	
x
11	1	TTL equals 0 during reassembly——在数据报组装期间生存时间为0	 	x
12	0	IP header bad (catchall error)——坏的IP首部（包括各种差错）	
x
12	1	Required options missing——缺少必需的选项	 	x
13	0	Timestamp request (obsolete)——时间戳请求（作废不用）	x	 
14	 	Timestamp reply (obsolete)——时间戳应答（作废不用）	x	 
15	0	Information request (obsolete)——信息请求（作废不用）	x	 
16	0	Information reply (obsolete)——信息应答（作废不用）	x	 
17	0	Address mask request——地址掩码请求	x	 
18	0	Address mask reply——地址掩码应答


过滤ICMP Echo请求包：

icmp.type == 8

6.6 HTTP协议

http.request.method：请求方法（GET、POST、PUT等）
http.response.code：响应码（200、404等）
http.host：请求的主机名
http.user_agent：客户端信息
过滤HTTP响应码404：

http.response.code == 404

6.7 DNS协议

dns.qry.name：查询域名
dns.qry.type：查询类型（A、AAAA、MX等）
dns.a：A记录返回IP地址
dns.flags.response：0表示请求，1表示响应
过滤所有DNS查询包：

dns.flags.response == 0

6.8 SSL/TLS协议

ssl.handshake.type：握手类型（客户端Hello、服务端Hello等）
ssl.record.version：协议版本
ssl.record.length：记录长度
过滤所有TLS客户端Hello包：

ssl.handshake.type == 1



7. 显示过滤器性能优化建议
当抓包文件巨大时，复杂过滤语法可能会导致Wireshark卡顿甚至崩溃。以下建议帮你提升效率：

尽量先用捕获过滤器减少抓包量

过滤表达式中避免使用contains和matches这类正则匹配，性能消耗大

尽量使用字段的等值或范围比较

对IP和端口的过滤尽量集中，不要写太多or条件

使用括号明确运算顺序，避免解析错误

分步骤过滤，先用粗过滤，再逐步精细化



8. 实用场景举例
8.1 定位特定主机通信

只看某台主机的所有流量：

ip.addr == 192.168.1.100

8.2 诊断TCP三次握手过程

过滤TCP SYN包：

tcp.flags.syn == 1 and tcp.flags.ack == 0

过滤TCP SYN+ACK包：

tcp.flags.syn == 1 and tcp.flags.ack == 1

过滤完成三次握手的包：

tcp.flags.ack == 1 and tcp.seq == tcp.ack - 1

8.3 抓取HTTP请求

过滤所有HTTP请求：

http.request

过滤POST请求：

http.request.method == "POST"

8.4 DNS问题排查

过滤DNS请求：

dns.flags.response == 0

过滤DNS响应：

dns.flags.response == 1

过滤查询失败的DNS响应（RCODE不为0）：

dns.flags.rcode != 0

8.5 网络攻击检测

过滤ICMP洪泛攻击（大量ICMP请求）：

icmp.type == 8

过滤TCP SYN洪泛攻击：

tcp.flags.syn == 1 and tcp.flags.ack == 0


9. 捕获过滤器更丰富的使用场景
9.1 按接口过滤

指定接口抓包：

tcpdump -i eth1

监听所有接口：

tcpdump -i any

9.2 指定MAC地址抓包

抓取源MAC地址是00:11:22:33:44:55的包：

ether src 00:11:22:33:44:55

目的MAC地址：

ether dst 00:11:22:33:44:55

9.3 抓特定协议

抓取HTTP流量（通常端口80端口）：

tcp port 80

抓取DNS流量：

udp port 53

抓取所有ARP包：

arp

9.4 按包大小过滤

抓包长度大于1000字节的包：

greater 1000

9.5 复杂组合示例

抓取目标是192.168.1.10且TCP端口是22或80的包：

dst host 192.168.1.10 and tcp and (dst port 22 or dst port 80)

抓取除ICMP外所有流量：

not icmp



10. 显示过滤器高级语法技巧
10.1 字段赋值判断

某些协议中字段可判断是否存在或赋值。

判断HTTP请求是否有Host头：

http.host
判断DNS查询名是否以某域名结尾（正则）：

dns.qry.name matches ".*\.cn$"
10.2 多字段范围过滤

过滤TCP目的端口是1024到65535的包（高端口）：

tcp.dstport >= 1024 and tcp.dstport <= 65535

10.3 空值判断

过滤没有TCP选项的包：

!tcp.options

10.4 按协议层级过滤

过滤所有包含HTTP但排除HTTPS的包：

http and not ssl

10.5 显示过滤器变量

Wireshark支持变量绑定和条件过滤，可在高级脚本和命令行用法中发挥作用，这里不做深讲。



11. 捕获过滤器 vs 显示过滤器


12. 常用命令参数总结
-i <interface>：指定接口
-c <count>：抓包数量限制
-s <snaplen>：抓包长度限制
-w <file>：写入文件
-r <file>：读取文件分析
-n：禁止DNS解析，直接显示IP
-v：详细模式
-e：显示链路层头部信息