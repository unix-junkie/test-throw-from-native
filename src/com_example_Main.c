/*-
 * $Id$
 */

#include <stdio.h>

#include "com_example_Main.h"

JNIEXPORT void JNICALL Java_com_example_Main_throwException(JNIEnv *env, jclass clazz) {
#if __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ >= 1070
	/*
	 * 10.7+ Implementation goes here
	 */
#else // __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__
#define __MAC_OS_X_VERSION_MAJOR__	__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ / 100
#define __MAC_OS_X_VERSION_MINOR__	__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ / 10 % 10
#define __MAC_OS_X_VERSION_UPDATE__	__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ % 10
	/*
	 * If the class is not found, java.lang.NoClassDefFoundError will be thrown.
	 */
	const jclass throwable = (*env)->FindClass(env, "java/lang/UnsupportedOperationException");
	if (throwable != NULL) {
		char message[64];
		sprintf(message, "Not implemented in Mac OS X %d.%d.%d", __MAC_OS_X_VERSION_MAJOR__, __MAC_OS_X_VERSION_MINOR__, __MAC_OS_X_VERSION_UPDATE__);
		(*env)->ThrowNew(env, throwable, message);
	}
#endif // __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__
}
