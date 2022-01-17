package com.example.client.dto;


/* Json example
{
    "header" : {
        "response_code" : "OK"
    },
    "body" : {
        "name" : "Ben",
        "age" : 24
    }
}
*/

public class Req<T> {
    
    private Header header;

    private T resBody;

    public static class Header {
        private String responseCode;

        public String getResponseCode() {
            return responseCode;
        }
        public void setResponseCode(String responseCode) {
            this.responseCode = responseCode;
        }
        @Override
        public String toString() {
            return super.toString();
        }
    }

    public Header getHeader() {
        return header;
    }
    public void setHeader(Header header) {
        this.header = header;
    }
    public T getResBody() {
        return resBody;
    }
    public void setResBody(T resBody) {
        this.resBody = resBody;
    }
    @Override
    public String toString() {
        return super.toString();
    }
}
