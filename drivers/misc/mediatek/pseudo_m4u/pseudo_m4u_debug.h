/*
 * Copyright (C) 2015 MediaTek Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef __PSEUDO_M4U_DEBUG_H__
#define __PSEUDO_M4U_DEBUG_H__

extern unsigned long gM4U_ProtectVA;

extern int __attribute__((weak)) __ddp_mem_test(unsigned long *pSrc,
	unsigned long pSrcPa,
	unsigned long *pDst, unsigned long pDstPa,
	int need_sync);

#ifdef M4U_TEE_SERVICE_ENABLE
extern int m4u_sec_init(void);
extern int m4u_config_port_tee(struct M4U_PORT_STRUCT *pM4uPort);
#endif

void m4u_dump_pgtable(void);
struct m4u_client_t *pseudo_create_client(void);
int pseudo_destroy_client(struct m4u_client_t *client);
int __pseudo_alloc_mva(struct m4u_client_t *client,
	int port, unsigned long va, unsigned long size,
	struct sg_table *sg_table, unsigned int flags,
	unsigned long *retmva);
int pseudo_dealloc_mva(struct m4u_client_t *client,
	int port, unsigned long mva);
struct device *pseudo_get_larbdev(int portid);
int pseudo_dump_all_port_status(struct seq_file *s);
int pseudo_dump_iova_reserved_region(void);

#endif
