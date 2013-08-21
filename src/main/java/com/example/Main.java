/*-
 * $Id$
 */
package com.example;

import static java.lang.System.loadLibrary;

/**
 * @author Andrew ``Bass'' Shcheglov (andrewbass@gmail.com)
 */
abstract class Main {
	private Main() {
		assert false;
	}

	private static native void throwException();

	/**
	 * @param args
	 */
	public static void main(final String args[]) {
		try {
			loadLibrary("test-throw-from-native");
			throwException();
		} catch (final UnsupportedOperationException uoe) {
			System.out.println("Exception from native method: " + uoe.getMessage());
		} catch (final UnsatisfiedLinkError ule) {
			System.out.println("Library not loaded: " + ule.getMessage());
		} catch (final Throwable t) {
			t.printStackTrace();
		}
	}
}
