/* Copyright (c) 2022 Intel Corporation
 * Copyright (c) 2020-2021 Alibaba Cloud
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _RATS_ERR_H
#define _RATS_ERR_H

#define ERR_CODE_CLASS_SHIFT	28
#define ERR_CODE_SUBCLASS_SHIFT 23
#define ERR_CODE_CLASS_MASK	0x70000000
#define ERR_CODE_SUBCLASS_MASK	0x0f800000
#define ERR_CODE_ERROR_MASK	((1 << ERR_CODE_SUBCLASS_SHIFT) - 1)
#define ERR_CODE_NAGATIVE	(1 << 31)

#define RATS_ERR_BASE	       (0 << ERR_CODE_CLASS_SHIFT)
#define RATS_ATTESTER_ERR_BASE (2 << ERR_CODE_CLASS_SHIFT)
#define RATS_VERIFIER_ERR_BASE (3 << ERR_CODE_CLASS_SHIFT)

/* The base of error code used by sgx-ecdsa */
#define SGX_ECDSA_ERR_BASE (0 << ERR_CODE_SUBCLASS_SHIFT)

/* The base of error code used by sgx-la */
#define SGX_LA_ERR_BASE (0 << ERR_CODE_SUBCLASS_SHIFT)

#define __RATS_ATTESTER_ERR_CODE(base, err)                                                        \
	(((RATS_ATTESTER_ERR_BASE + (base)) & ERR_CODE_CLASS_MASK) | ((err)&ERR_CODE_ERROR_MASK) | \
	 ERR_CODE_NAGATIVE)

#define SGX_ECDSA_ATTESTER_ERR_CODE(err) __RATS_ATTESTER_ERR_CODE(SGX_ECDSA_ERR_BASE, err)

#define SGX_LA_ATTESTER_ERR_CODE(err) __RATS_ATTESTER_ERR_CODE(SGX_LA_ERR_BASE, err)

#define __RATS_VERIFIER_ERR_CODE(base, err)                                                        \
	(((RATS_VERIFIER_ERR_BASE + (base)) & ERR_CODE_CLASS_MASK) | ((err)&ERR_CODE_ERROR_MASK) | \
	 ERR_CODE_NAGATIVE)

#define SGX_ECDSA_VERIFIER_ERR_CODE(err) __RATS_VERIFIER_ERR_CODE(SGX_ECDSA_ERR_BASE, err)

#define SGX_LA_VERIFIER_ERR_CODE(err) __RATS_VERIFIER_ERR_CODE(SGX_LA_ERR_BASE, err)

typedef enum {
	RATS_ATTESTER_ERR_NONE = RATS_ATTESTER_ERR_BASE,
	RATS_ATTESTER_ERR_UNKNOWN,
	RATS_ATTESTER_ERR_NO_MEM,
	RATS_ATTESTER_ERR_NOT_REGISTERED,
	RATS_ATTESTER_ERR_INVALID,
	RATS_ATTESTER_ERR_CPU_UNSUPPORTED,
	RATS_ATTESTER_ERR_DLOPEN,
	RATS_ATTESTER_ERR_INIT,
	RATS_ATTESTER_ERR_NO_TOOL,
	RATS_ATTESTER_ERR_CURL,
} rats_attester_err_t;

typedef enum {
	RATS_VERIFIER_ERR_NONE = RATS_VERIFIER_ERR_BASE,
	RATS_VERIFIER_ERR_UNKNOWN,
	RATS_VERIFIER_ERR_NO_MEM,
	RATS_VERIFIER_ERR_NOT_REGISTERED,
	RATS_VERIFIER_ERR_INVALID,
	RATS_VERIFIER_ERR_DLOPEN,
	RATS_VERIFIER_ERR_INIT,
	RATS_VERIFIER_ERR_NO_TOOL,
} rats_verifier_err_t;

#endif
