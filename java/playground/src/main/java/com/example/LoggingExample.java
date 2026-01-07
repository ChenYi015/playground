package com.example;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class LoggingExample {

    private static final Logger logger = LoggerFactory.getLogger(LoggingExample.class);

    public static void main(String[] args) {
        logger.trace("This is some trace message.");
        logger.debug("This is some debug message.");
        logger.info("This is some info message.");
        logger.warn("This is some warning message.");
        logger.error("This is some error message.");
    }
}