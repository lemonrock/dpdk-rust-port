# Which Poll Mode Drivers (PMD) to port?


## Important

* Amazon
	* `net/ena`
		* Amazon Elastic Network Adapator
* Intel® (a lot of documentation is linked as references [at wikipedia](https://en.wikipedia.org/wiki/Network_interface_controller)).
	* `net/i40e`
		* 10/25/40 Gbps Intel® Ethernet 700 Series Controllers & Network Adapters
			* Intel® Ethernet Controller XXV710
				* Intel® Ethernet Controller XXV710-AM1
				* Intel® Ethernet Controller XXV710-AM2
			Intel® Ethernet Network Adapter XXV710 Series
				* Intel® Ethernet Network Adapter XXV710-DA1
				* Intel® Ethernet Network Adapter XXV710-DA1 for Open Compute Project
				* Intel® Ethernet Network Adapter XXV710-DA2
				* Intel® Ethernet Network Adapter XXV710-DA2 for Open Compute Project
			* Intel® Ethernet Controller XL710 Series
				* Intel® Ethernet Controller XL710-AM1	
				* Intel® Ethernet Controller XL710-AM2	
				* Intel® Ethernet Controller XL710-BM1
				* Intel® Ethernet Controller XL710-BM2
			* Intel® Ethernet Server Adapter XL710 Series
				* Intel® Ethernet Converged Network Adapter XL710-QDA1
				* Intel® Ethernet Server Adapter XL710-QDA1 for Open Compute Project
				* Intel® Ethernet Converged Network Adapter XL710-QDA2
				* Intel® Ethernet Server Adapter XL710-QDA2 for Open Compute Project
			* Intel® Ethernet Controller X710 Series
				* Intel® Ethernet Controller X710-AM2
				* Intel® Ethernet Controller X710-AT2
				* Intel® Ethernet Controller X710-BM2
				* Intel® Ethernet Controller X710-TM4
			* Intel® Ethernet Network Adapter X710 Series
				* Intel® Ethernet Converged Network Adapter X710-DA2
				* Intel® Ethernet Server Adapter X710-DA2 for Open Compute Project
				* Intel® Ethernet Network Adapter X710-DA2 for Open Compute Project 3.0
				* Intel® Ethernet Converged Network Adapter X710-DA4
				* Intel® Ethernet Network Adapter X710-DA4 for Open Compute Project 3.0
				* Intel® Ethernet Network Adapter X710-T2L
				* Intel® Ethernet Converged Network Adapter X710-T4
			* Intel® Ethernet Network Adapter X722 Series
				* Intel® Ethernet Network Adapter X722-DA2
				* Intel® Ethernet Network Adapter X722-DA4
	* `net/ice`
		* 10/25/50/100 Gbps Intel® Ethernet 810 Series Network Adapters
			* Intel® Ethernet Controller E810
	* `net/fm10k`
		* Intel® FM10000 (FM10K) family of 40GbE/100GbE adapters
			* Intel® Ethernet Multi-host Controller FM10420
			* There is also a FM10840 but DPDK does not support this
	* `net/ixgbe` (statistics most be polled at least every 288 seconds or so due to a hardware bug)
		* ?Intel® Ethernet Connection X557 Series?
			* ?Intel® Ethernet Connection X557-AT?
			* ?Intel® Ethernet Connection X557-AT2?
			* ?Intel® Ethernet Connection X557-AT4?
		* Intel® Ethernet Controller X550 Series (Sageville)
			* Intel® Ethernet Controller X550-AT
			* Intel® Ethernet Controller X550-AT2
			* Intel® Ethernet Controller X550-BT2
		* Intel® Ethernet Converged Network Adapter X550 Series
			* Intel® Ethernet Converged Network Adapter X550-T1
			* Intel® Ethernet Converged Network Adapter X550-T2
		* Intel® Ethernet Controller X540 Series
			* Intel® Ethernet Controller X540-AT2
			* Intel® Ethernet Controller X540-BT2
		* Intel® Ethernet Converged Network Adapter X540 Series (Spring Fountain)
			* Intel® Ethernet Converged Network Adapter X540-T1
			* Intel® Ethernet Converged Network Adapter X540-T2
		* Intel® Ethernet Server Bypass Adapter X540 series
			* Intel® Ethernet Server Bypass Adapter X540-T2 (Discontinued)
		* Intel® 82599 10 Gigabit Ethernet Controller (Intel considers this a 500 Series Controller)
			* Intel® Ethernet Server Adapter X520 Series
				* Intel® Ethernet Server Adapter X520-DA1 for Open Compute Project (Niantic)
				* Intel® Ethernet Converged Network Adapter X520-DA2
				* Intel® Ethernet Server Adapter X520-DA2 for Open Compute Project
				* Intel® Ethernet Converged Network Adapter X520-LR1
				* Intel® Ethernet Converged Network Adapter X520-QDA1 (Discontinued)
				* Intel® Ethernet Converged Network Adapter X520-SR1
				* Intel® Ethernet Converged Network Adapter X520-SR2
				* Intel® Ethernet Converged Network Adapter X520-T2 (Discontinued)
			* Intel® 82599EB 10 Gigabit Ethernet Controller
			* Intel® 82599EN 10 Gigabit Ethernet Controller
				* Intel® Ethernet Server Bypass Adapter X520 Series
					* Intel® Ethernet Server Bypass Adapter X520-LR2 (Discontinued)
					* Intel® Ethernet Server Bypass Adapter X520-SR2 (Discontinued)
			* Intel® 82599ES 10 Gigabit Ethernet Controller
		* Intel® 82598 10 Gigabit Ethernet Controller (?Legacy)
			* Intel® 82598EB 10 Gigabit Ethernet Controller
				* Intel® 10 Gigabit AT Server Adapter
* Broadcom
	* `net/bnxt`
		* Broadcom BCM5730X NetXtreme-C® Family of Ethernet Network Controllers
			* M150c - Single-port 40/50 Gigabit Ethernet Adapter
			* P150c - Single-port 40/50 Gigabit Ethernet Adapter
			* P225c - Dual-port 10/25 Gigabit Ethernet Adapter
		* Broadcom BCM574XX/BCM575XX NetXtreme-E® Family of Ethernet Network Controllers
			* M125P - Single-port OCP 2.0 10/25 Gigabit Ethernet Adapter
			* M150P - Single-port OCP 2.0 50 Gigabit Ethernet Adapter
			* M150PM - Single-port OCP 2.0 Multi-Host 50 Gigabit Ethernet Adapter
			* M210P - Dual-port OCP 2.0 10 Gigabit Ethernet Adapter
			* M210TP - Dual-port OCP 2.0 10 Gigabit Ethernet Adapter
			* M11000G - Single-port OCP 2.0 10/25/50/100 Gigabit Ethernet Adapter
			* N150G - Single-port OCP 3.0 50 Gigabit Ethernet Adapter
			* M225P - Dual-port OCP 2.0 10/25 Gigabit Ethernet Adapter
			* N210P - Dual-port OCP 3.0 10 Gigabit Ethernet Adapter
			* N210TP - Dual-port OCP 3.0 10 Gigabit Ethernet Adapter
			* N225P - Dual-port OCP 3.0 10/25 Gigabit Ethernet Adapter
			* N250G - Dual-port OCP 3.0 50 Gigabit Ethernet Adapter
			* N410SG - Quad-port OCP 3.0 10 Gigabit Ethernet Adapter
			* N410SGBT - Quad-port OCP 3.0 10 Gigabit Ethernet Adapter
			* N425G - Quad-port OCP 3.0 10/25 Gigabit Ethernet Adapter
			* N1100G - Single-port OCP 3.0 10/25/50/100 Gigabit Ethernet Adapter
			* N2100G - Dual-port OCP 3.0 10/25/50/100 Gigabit Ethernet Adapter
			* N2200G - Dual-port OCP 3.0 10/25/50/100/200 Gigabit Ethernet Adapter
			* P150P - Single-port 50 Gigabit Ethernet Adapter
			* P210P - Dual-port 10 Gigabit Ethernet Adapter
			* P210TP - Dual-port 10 Gigabit Ethernet Adapter
			* P225P - Dual-port 10/25 Gigabit Ethernet Adapter
			* P410SG - Quad-port 10 Gigabit Ethernet Adapter
			* P410SGBT - Quad-port 10 Gigabit Ethernet Adapter
			* P425G - Quad-port 10/25 Gigabit Ethernet Adapter
			* P1100G - Single-port 10/25/50/100 Gigabit Ethernet Adapter
			* P2100G - Dual-port 10/25/50/100 Gigabit Ethernet Adapter
			* P2200G - Dual-port 10/25/50/100/200 Gigabit Ethernet Adapter
		* Broadcom BCM588XX Stingray Family of SmartNIC Adapters
			* PS410T - Quad-port 10 Gigabit Ethernet SmartNIC
			* PS225 - Dual-port 25 Gigabit Ethernet SmartNIC
			* PS250 - Dual-Port 50 Gigabit Ethernet SmartNIC
		* Broadcom StrataGX® BCM5871X Series of Communications Processors
			* These are ARM based
* Virtual
	* `net/vhost` (Supported by QEMU)
	* `net/virtio` (Supported by QEMU)
* Bonding
	* `net/bonding`


## Not Yet

* Marvell
	* `net/mvneta`
		*  Marvell NETA 1/2.5 Gbps adapter
			* <https://www.marvell.com/embedded-processors/armada-3700/>
	* `net/mvpp2`
		* Marvell PPv2 (Packet Processor v2) 1/10 Gbps adapter
			* <https://www.marvell.com/embedded-processors/armada-70xx/>
			* <https://www.marvell.com/embedded-processors/armada-80xx/>
* Microsoft HyperV NetVSC
	* `net/netsvc`
	* `net/vdev_netvsc`
* AMD
	* `net/axgbe`
		* AMD EPYC™ EMBEDDED 3000 family <https://www.amd.com/en/products/embedded-epyc-3000-series>
* Chelsio
	* `net/cxgbe`
		* Chelsio Terminator 10/25/40/100 Gbps family of adapters
* Intel
	* `net/intel_vf`
		* SR-IOV
* Mellanox
	* `net/mlx5`
		* Mellanox ConnectX-4
		* Mellanox ConnectX-4 Lx
		* Mellanox ConnectX-5
		* Mellanox ConnectX-6
		* Mellanox ConnectX-6 Dx
		* Mellanox BlueField


## Rejected


### Linux centric

* `net/af_packet`
* `net/af_xdp`
	* Provides the potential for high performance on Linux with existing drivers
* `net/kni`
	* Share the Linux kernel networking stack with DPDK
* `net/memif`
	* Share packets with applications using shared memory
* `net/null`
* `net/pcap_ring`
* `net/tap`
	* Send and receive raw ethernet packets to a local 'socket'


### Not actually network drivers

* `net/fail_safe`
* `net/softnic`


### Untrustworthy

* Huawei
	* `net/hinic`
		* Huawei Ethernet Controller Hi1822


### Legacy

* QLogic (now Marvell, was Cavium)
	* `net/bnx2x` 
	* `net/qede`
		* FastLinQ QL4xxxx 10G/25G/40G/50G/100G Intelligent Ethernet Adapters (IEA)
		* Converged Network Adapters (CNA)
* Intel
	* e1000, e1000e and e1000em
		* qemu-kvm emulated Intel® 82540EM Gigabit Ethernet Controller (qemu e1000 device)
		* VMware emulated Intel® 82545EM Gigabit Ethernet Controller
		* VMware emulated Intel® 8274L Gigabit Ethernet Controller
		* Intel® 82540 Gigabit Ethernet Controller)
			* Intel® 82540EM Gigabit Ethernet Controller
			* Intel® 82540EP Gigabit Ethernet Controller
		* Intel® 82545 Gigabit Ethernet Controller
			* Intel® 82545GM Gigabit Ethernet Controller
				* Intel® 82545EM Gigabit Ethernet Controller (PCI-X)
				* Intel® PRO/1000 MF Server Adapter (PCI-X)
				* Intel® PRO/1000 MF Server Adapter LX (PCI-X)
		* Intel® 82546 Gigabit Ethernet Controller
			* Intel® 82546EB Gigabit Ethernet Controller (PCI-X)
			* Intel® 82546GB Gigabit Ethernet Controller
				* Intel® PRO/1000 MF Dual Port Server Adapter (PCI-X)
				* Intel® PRO/1000 MT Dual Port Server Adapter (PCI-X)
		* Intel® 82574 Gigabit Ethernet Controller
			* Intel® 82574L Gigabit Ethernet Controller
				* Intel® Gigabit CT Desktop Adapter
			* Intel® 82574IT Gigabit Ethernet Controller
		* Intel® 82573 Gigabit Ethernet Controller
			* Intel® 82573E Gigabit Ethernet Controller
			* Intel® 82573L Gigabit Ethernet Controller
			* Intel® 82573V Gigabit Ethernet Controller
		* Intel® 82572 Gigabit Ethernet Controller
			* Intel® 82572EI Gigabit Ethernet Controller
		* Intel® 82571 Gigabit Ethernet Controller
			* Intel® 82571EB Gigabit Ethernet Controller 
				* Intel® PRO/1000 PF Dual Port Server Adapter
				* Intel® PRO/1000 PT Dual Port Server Adapter
				* Intel® PRO/1000 PT Quad Port Low Profile Server Adapter
				* Intel® PRO/1000 PT Quad Port Server Adapter
		* PCH2
		* Intel® 82579 Gigabit Ethernet Controller
			* Intel® 82579LM Gigabit Ethernet PHY
			* Intel® 82579V Gigabit Ethernet PHY
			* Intel® Platform Controller Hub (PCH) Family
				* ?Intel® C612 Chipset
				* ?Intel® X99 Chipset
		* Intel® Ethernet Connection I219
			* Intel® Ethernet Connection I219-LM
			* Intel® Ethernet Connection I219-V
		* Intel® Ethernet Connection I218
			* Intel® Ethernet Connection I218-LM
			* Intel® Ethernet Connection I218-V
		* Intel® Ethernet Connection I217
			* Intel® Ethernet Connection I217-LM
			* Intel® Ethernet Connection I217-V
		* Intel® 82567 Gigabit Ethernet PHY (also known as Intel® 82567 Gigabit Platform)
			* Intel® 82567V Gigabit Ethernet PHY
			* Intel® 82567LM Gigabit Ethernet PHY
			* Intel® I/O Controller Hub 10 (ICH10) Family
				* Intel® 82801JIB ICH10 Consumer Base (ICH10)
				* Intel® 82801JIR ICH10 RAID (ICH10R) Corporate Family
				* Intel® 82801JD ICH10 Corporate Base (ICH10D)
				* Intel® 82801JDO ICH10 Digital Office (ICH10DO)
		* Intel® 82566 Gigabit Ethernet PHY (also known as Intel® 82566 Gigabit Platform LAN Connect device)
			* Intel® 82566DC Gigabit Ethernet PHY
			* Intel® 82566DM Gigabit Ethernet PHY
			* Intel® 82566MC Gigabit Ethernet PHY
			* Intel® 82566MM Gigabit Ethernet PHY
			* Intel® I/O Controller Hub 8 (Intel® ICH8) Family
				* Intel® 82801HB ICH8 I/O Controller Hub (Base)
				* Intel® 82801HR ICH8R I/O Controller Hub (RAID)
				* Intel® 82801HDH ICH8DH I/O Controller Hub (Digital Home)
				* Intel® 82801HDO ICH8DO I/O Controller Hub (Digital Office)
				* Intel® 82801HBM ICH8M I/O Controller Hub (Mobile Base)
				* Intel® 82801HEM ICH8M-E I/O Controller Hub (Mobile Enhanced)
			* Intel® I/O Controller Hub 9 (ICH9) Family	
				* Intel® 82801IB ICH9 I/O Controller Hub
				* Intel® 82801IR ICH9R I/O Controller Hub
				* Intel® 82801IH ICH9DH I/O Controller Hub
				* Intel® 82801IO ICH9DO I/O Controller Hub
				* Intel® 82801IBM ICH9M I/O Controller Hub
				* Intel® 82801IEM ICH9M-E I/O Controller Hub
				* Intel® ICH9M-SFF ICH9 Controller Hub
	* `net/igb`
		* Intel® 82580 10 Gigabit Ethernet Controller
			* Intel® 82580DB 10 Gigabit Ethernet Controller
			* Intel® 82580EB 10 Gigabit Ethernet Controller
		* Intel® 82576 Gigabit Ethernet Controller
			* Intel® 82576EB Gigabit Ethernet Controller
				* Intel® Gigabit EF Dual Port Server Adapter
				* Intel® Gigabit ET Dual Port Server Adapter
			* Intel® Gigabit ET2 Quad Port Server Adapter
			* (Not Supported: Intel® 82576NS Gigabit Ethernet Controller)
		* Intel® Ethernet Controller I354
		* Intel® Ethernet Controller I350
			* Intel® Ethernet Controller I350-AM2
			* Intel® Ethernet Controller I350-AM4
			* Intel® Ethernet Controller I350-BT2
			* Intel® Ethernet Network Adapter I350-T4 for OCP 3.0
		* Intel® Ethernet Server Adapter I350
			* Intel® Ethernet Server Adapter I350-F2
			* Intel® Ethernet Server Adapter I350-F4
			* Intel® Ethernet Server Adapter I350-T2
			* Intel® Ethernet Server Adapter I350-T2V2
			* Intel® Ethernet Server Adapter I350-T4V2	
		* Intel® Ethernet Controller I211
			* Intel® Ethernet Controller I211-AT
		* Intel® Ethernet Controller I210
			* Intel® Ethernet Controller I210-AT
			* Intel® Ethernet Controller I210-CL
			* Intel® Ethernet Controller I210-CS
			* Intel® Ethernet Controller I210-IS
			* Intel® Ethernet Controller I210-IT
		* Intel® Ethernet Server Adapter I210
			* Intel® Ethernet Server Adapter I210-T1
		* DH89xx
	* Other (probably not DPDK supported)
		* Intel® 82597 10 Gigabit Ethernet Controller
			* Intel® 82597EX 10 Gigabit Ethernet Controller
		* Intel® 82578 Gigabit Ethernet PHY
			* Intel® 82578DC Gigabit Ethernet PHY
			* Intel® 82578DM Gigabit Ethernet PHY
		* Intel® 82577 Gigabit Ethernet PHY
			* Intel® 82577LC Gigabit Ethernet PHY	
			* Intel® 82577LM Gigabit Ethernet PHY
		* Intel® 82575 Gigabit Ethernet Controller
			* Intel® 82575EB Gigabit Ethernet Controller
		* Intel® 82564 Gigabit Ethernet PHY
			* Intel® 82564EB Gigabit Ethernet PHY
		* Intel® 82563 Gigabit Ethernet PHY
			* Intel® 82563EB Gigabit Ethernet PHY
		* Intel® 82547 Gigabit Ethernet Controller
			* Intel® 82547GI Gigabit Ethernet Controller (PCI-X)
		* Intel® 82544 Gigabit Ethernet Controller (PCI-X)
			* Intel® 82544EI Gigabit Ethernet Controller
			* Intel® 82544GC Gigabit Ethernet Controller
		* Intel® 82543 Gigabit Ethernet Controller (PCI)
			* Intel® 82543GC Gigabit Ethernet Controller
		* (There is no Intel® 82542 Gigabit Ethernet Controller or PHY)
		* Intel® 82541 Gigabit Ethernet Controller
			* Intel® 82541ER Gigabit Ethernet Controller
			* Intel® 82541GI Gigabit Ethernet Controller
			* Intel® 82541PI Gigabit Ethernet Controller 
				* Intel® PRO/1000 GT Desktop Adapter
		* (There is no Intel® 82565 Gigabit Ethernet Controller or PHY)
		* Intel® Ethernet Switch FM6000 Series
			* Intel® Ethernet Switch FM6324
			* Intel® Ethernet Switch FM6348
			* Intel® Ethernet Switch FM6364
			* Intel® Ethernet Switch FM6724
			* Intel® Ethernet Switch FM6764
		* Intel® Ethernet Switch FM5000 Series
			* Intel® Ethernet Switch FM5224
		* Intel® Ethernet Switch FM4000 Series
			* Intel® Ethernet Switch FM4105
			* Intel® Ethernet Switch FM4112
			* Intel® Ethernet Switch FM4212
			* Intel® Ethernet Switch FM4224
			* Intel® Ethernet Switch FM4410
		* Intel® Ethernet Switch FM2000 Series
			* Intel® Ethernet Switch FM2112
			* Intel® Ethernet Switch FM2212
			* Intel® Ethernet Switch FM2224
		* Intel® Fast Ethernet Network Connections (ie 100Mbit)
			* Intel® 82562EP Fast Ethernet PHY
			* Intel® 82562ET Fast Ethernet PHY
			* Intel® 82562EZ Fast Ethernet PHY
			* Intel® 82562GT Fast Ethernet PHY
			* Intel® 82562GZ Fast Ethernet PHY
			* Intel® 82562V Fast Ethernet PHY (previously used in Intel® I/O Controller Hub 8 (Intel® ICH8) Family and Intel® I/O Controller Hub 9 (ICH9) Family	) (also known as Intel® 82562V Platform LAN Connect device)
			* Intel® 82559ER Fast Ethernet Controller
			* Intel® 82552V Fast Ethernet PHY 
			* Intel® 82551ER Fast Ethernet Controller
			* Intel® 82551IT Fast Ethernet Controller
			* Intel® 82551QM Fast Ethernet Controller
		* Intel® PRO/100 S Server Adapter Series (ie 100Mbit)
			* Intel® PRO/100 S Dual Port Server Adapter
			* Intel® PRO/100 S Server Adapter
* VMware
	* `net/vmxnet3`
		* The future is virtio
		* VMware is simply no longer common for Linux servers in the cloud
* NXP
	* `net/dpaa`
* Cisco
	* `net/enic`
		* Cisco System VIC Ethernet NICs (vNICs) used in Cisco UCS servers
* Mellanox
	* `net/mlx4`
		* Mellanox ConnectX-3
		* Mellanox ConnectX-3 Pro
* Cavium (now Marvell)
	* `net/liquidio`
		* LiquidIO II CN2350 210SV/225SV
		* LiquidIO II CN2350 210SVPT
		* LiquidIO II CN2360 210SV/225SV
		* LiquidIO II CN2360 210SVPT
	* `net/octeontx`
		* OCTEON TX SoC CN83xx
	* `net/thunderx`
		* Cavium ThunderX SoC family


### Not Common

* Atomic Rules Arkville
	* `net/ark`
* Atlantic
	* `net/atlantic`
		* AQtion family of chipsets: AQC107/AQC108/AQC109 see (Aquantia Official Website)[https://www.aquantia.com/products/client-connectivity/]
* Wind River
	* `net/avp`
		* Accelerated Virtual Port (AVP)
* NXP
	* `net/dpaa2`
	* `net/enetc`
		* LS1028 SoC
	* `net/pfe`
		* LS1012 SoC
* Hisilicon
	* `net/hns3`
		* Hisilicon Kunpeng 920 SoC
* Pensando
	* `net/ionic`
		* [Naples DSC-25](https://pensando.io/assets/documents/Naples-25_ProductBrief_10-2019.pdf)
		* [Naples DSC-100](https://pensando.io/assets/documents/Naples_100_ProductBrief-10-2019.pdf)
* Intel
	* `net/ipn3ke`
		* Intel® FPGA PAC (Programmable Acceleration Card) N3000 based on the Intel® Ethernet Controller X710/XXV710 and Intel® Arria 10 FPGA.
	* `ifc`
		* IFC
* Netcope
	* `net/nfb`
		* Netcope FPGA Boards NFB-40G2, NFB-100G2 and NFB-200G2QL
		* Silicom FB2CGG3 card
	* `net/szedata2` (?why the overlap for `nfb`)
		* Netcope FPGA Boards NFB-40G2, NFB-100G2 and NFB-200G2QL
		*  Silicom FB2CGG3 card
* Netronome
	* `net/nfp` 
		* Network Flow Processor 4xxx (NFP-4xxx)
		* Network Flow Processor 6xxx (NFP-6xxx)
* Cavium (now Marvell)
	* `net/octeontx2`
* Solarflare
	* `net/sfc_efx`
		* Solarflare SFN7xxx and SFN8xxx family of 10/40 Gbps adapters
		* Solarflare XtremeScale X2xxx family of 10/25/40/50/100 Gbps adapters


# What features do we want?

* Link Status
	* Speed
	* Duplex mode
	* Up / Down
* MACsec IEEE 802.1 AE (but it is rare)

## Very useful

* Receive Side Steering (RSS)
* Multiple send and receive queues that are highly configurable
* Layer 3 (IPv4 / IPv6) checksum offload
* Layer 4 (TCP / UDP) checksum offload
* Large Receive Offload (LRO)
* Large Send Offload (LSO)
	* Overlaps with TCP Segmentation Offload (TSO)
	* Overlaps with Generic Segmentation Offload (GSO)
* Vector (SSE) functions
* Scatter / Gather Transmit
* Scatter / Gather Receive
* Transmit Side Steering (TSS)


## Somewhat useful

* VLAN offload
* Receive ethernet checksum (CRC) stripping
* Various filters, eg
	* Unicast and multicast MAC filtering
	* Ethertype filtering
	* N-tuple filtering
* Ethernet Flow Control (START / STOP)
* Jumbo frames


## To introduce

* NIC failover or hotplug support
	* Explore the `net/fail_safe` Poll Mode Driver.
	
	
# Documentaion




## Intel

* fm10k
	* Driver has a 'base' extracted from FreeBSD (`drivers/net/fm10k/base`)
		* Replace `fm10k_osdep.h` with our own concrete implementations
		* Version is in Makefile in `drivers/net/fm10k/Makefile`
		* We should be able to compile this standalone of DPDK
		* Remaining code of interest is `fm10k_ethdev.c`, `fm10k_rxtx_vec.c` and `fm10k_rxtx.c`, which, whilst it uses `rte_ethdev`, should be possible to isolated
	* Intel® Ethernet Multi-host Controller FM10420
		* [Datasheet PDF](https://www.intel.com/content/www/us/en/embedded/products/networking/ethernet-multi-host-controller-fm10000-family-datasheet.html?asset=13074)
		* [Product Brief PDF](https://www.intel.com/content/www/us/en/embedded/products/networking/ethernet-multi-host-controller-fm10000-family-product-brief.html)
* ice
	* Driver has a 'base' extracted from FreeBSD (`drivers/net/ice/base`)
		* Replace `ice_osdep.h` with our own concrete implementations
		* Remaining code should be possible to isolate and understand (basic device, flow director filters, AVX2 and SSE, Rx-Tx)
* i40e
	* Driver has a 'base' extracted from FreeBSD (`drivers/net/i40e/base`)
		* Replace `i40e_osdep.h` with our own concrete implementations
		* Remaining code should be possible to isolate and understand (basic device, flow director filters, AVX2 / SSE / PPC Altivec / Arm Neon, Rx-Tx)
		* More complex as also has 'VF' code
	* Intel® Ethernet Controller XXV710 (Fortville)
		[Datasheet](http://www.intel.com/content/www/us/en/embedded/products/networking/xl710-10-40-controller-datasheet.html)
		[Product Brief](https://www.intel.com/content/www/us/en/embedded/products/networking/ethernet-controller-xxv710-am1-am2-brief.html)
	* Intel® Ethernet Controller XL710 Series (Fortville)
		* [Datasheet](http://www.intel.com/content/www/us/en/embedded/products/networking/xl710-10-40-controller-datasheet.html)
		* [Product Brief](https://www.intel.com/content/www/us/en/embedded/products/networking/xl710-10-40-gbe-controller-brief.html)
	* Intel® Ethernet Controller X710 Series (Fortville) (Discontinued)
		* [Datasheet](http://www.intel.com/content/www/us/en/embedded/products/networking/xl710-10-40-controller-datasheet.html)
		* [Product Brief](http://www.intel.com/content/dam/www/public/us/en/documents/product-briefs/xl710-10-40-gbe-controller-brief.pdf)
	* Intel® Ethernet Network Adapter XXV710 Series
		* [Product Brief](http://www.intel.com/content/www/us/en/ethernet-products/network-adapters/ethernet-xxv710-brief.html)
	* Intel® Ethernet Server Adapter XL710 Series
		* [Product Brief](https://www.intel.com/content/www/us/en/ethernet-products/converged-network-adapters/ethernet-xl710-brief.html)
	* Intel® Ethernet Network Adapter X722 Series
		* [Product Brief](https://www.intel.com/content/dam/www/public/us/en/documents/product-briefs/ethernet-network-adapter-x722-product-brief.pdf)
		* Intel® C628 Chipset
	* Intel® Ethernet Network Adapter X710 Series
		* [Product Brief](http://www.intel.com/content/dam/www/public/us/en/documents/product-briefs/ethernet-x710-brief.pdf)
* ixgbe
	* Driver has a 'base' extracted from FreeBSD (`drivers/net/ixgbe/base`)
		* Replace `ixgbe_osdep.h` with our own concrete implementations
	* ?Intel® Ethernet Connection X557-AT? (Coppervale)
		* [Datasheet](http://www.intel.com/content/www/us/en/embedded/products/networking/x557-at-at2-at4-10gbe-phy-datasheet.html)
		* [Product Brief](http://www.intel.com/content/www/us/en/embedded/products/networking/ethernet-connection-x557-product-brief.html)
		* Due to be discontinued Q1 2020.
	* Intel® Ethernet Converged Network Adapter X550
		* [Intel® Ethernet Controller X550 Specification Update, December 2019](https://www.intel.com/content/dam/www/public/us/en/documents/specification-updates/ethernet-x550-spec-update.pdf)
		* [Product Brief PDF](www.intel.com/content/www/us/en/embedded/products/networking/ethernet-x550-brief.html)
		* [Datasheet PDF](www.intel.com/content/www/us/en/embedded/products/networking/ethernet-x550-datasheet.html)
	* Intel® Ethernet Controller X540 Series (Sageville)
		* [Datasheet PDF](http://www.intel.com/content/www/us/en/embedded/products/networking/ethernet-x550-datasheet.html)
		* [Product Brief PDF](http://www.intel.com/content/www/us/en/embedded/products/networking/ethernet-x550-brief.html)
	* Intel® Ethernet Converged Network Adapter X540
		* [Product Brief](https://www.intel.com/content/www/us/en/products/docs/network-io/ethernet/network-adapters/ethernet-x540-t2-brief.html)
	* Intel® Ethernet Controller X540 Series (Twinville)
		* [Datasheet PDF](http://www.intel.com/content/www/us/en/network-adapters/10-gigabit-network-adapters/ethernet-x540-datasheet.html)
		* [Product Brief PDF](http://www.intel.com/content/www/us/en/network-adapters/10-gigabit-network-adapters/ethernet-x540-brief.html)
	* Intel® Ethernet Server Adapter X520
		* [Product Brief](https://www.intel.com/content/www/us/en/products/docs/network-io/ethernet/network-adapters/ethernet-x520-server-adapters-brief.html)
		* [X520-DA1/X520-DA2 for Open Compute Project Product Brief](https://www.intel.com/content/www/us/en/products/docs/network-io/ethernet/network-adapters/server-adapter-x520-da1-da2-for-ocp-brief.html)
		* Reuses Intel® 82599 10 Gigabit Ethernet Controller
	* Intel® 82599EB 10 Gigabit Ethernet Controller (Niantic; X520 series)
		* [Datasheet PDF](https://www.intel.com/content/www/us/en/embedded/products/networking/82599-10-gbe-controller-datasheet.html?asset=2377)
		* [Product Brief](https://www.intel.com/content/www/us/en/embedded/products/networking/82599-10-gbe-controller-brief.html)
* igb (and e1000)
	* Driver has a 'base' extracted from FreeBSD (`drivers/net/e1000/base`)
		* Replace `e1000_osdep.h` *and* `e1000_osdep.c` with our own concrete implementations
	* Use only the C code files starting `igb_`.
* vmxnet3
	* Driver has a 'base' extracted from FreeBSD (`drivers/net/vmxnet3`)
		* Replace `vmxnet3_osdep.h` with our own concrete implementations