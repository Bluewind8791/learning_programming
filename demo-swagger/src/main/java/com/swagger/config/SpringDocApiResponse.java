package com.swagger.config;

import java.lang.annotation.Documented;

import io.swagger.v3.oas.annotations.responses.ApiResponse;
import io.swagger.v3.oas.annotations.responses.ApiResponses;

@Documented
@ApiResponses(value = {
    @ApiResponse(
        responseCode = "200", 
        description = "OK"
    ),
    @ApiResponse(
        responseCode = "400", 
        description = "Bad Request"
    )
})
public @interface SpringDocApiResponse {}
