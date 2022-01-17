package com.example.aop.dto;

public class User {
    
    private String id;
    private String pw;
    private String email;

    public String getEmail() {
        return email;
    }
    public String getId() {
        return id;
    }
    public String getPw() {
        return pw;
    }
    public void setEmail(String email) {
        this.email = email;
    }
    public void setId(String id) {
        this.id = id;
    }
    public void setPw(String pw) {
        this.pw = pw;
    }

    @Override
    public String toString() {
        return ("User: id=" + id + ", pw=" +pw+ ", email=" +email);
    }
}
