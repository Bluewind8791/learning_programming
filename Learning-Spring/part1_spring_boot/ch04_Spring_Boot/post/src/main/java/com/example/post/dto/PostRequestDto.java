package com.example.post.dto;

import com.fasterxml.jackson.annotation.JsonProperty;

public class PostRequestDto {
  
  private String account;
  private String email;
  private String address;
  private String password;

  @JsonProperty("phone_number") // JSON의 phone_number을 이 변수에 매칭
  private String phoneNumber; // phone_number
  

  public String getPhoneNumber() {
    return phoneNumber;
  }
  public void setPhoneNumber(String phoneNumber) {
    this.phoneNumber = phoneNumber;
  }


  public String getAccount() {
    return account;
  }
  public String getAddress() {
    return address;
  }
  public String getEmail() {
    return email;
  }
  public String getPassword() {
    return password;
  }
  public void setAccount(String account) {
    this.account = account;
  }
  public void setAddress(String address) {
    this.address = address;
  }
  public void setEmail(String email) {
    this.email = email;
  }
  public void setPassword(String password) {
    this.password = password;
  }

  @Override
  public String toString() {
    return "PostRequestDto\n account=" +account+ "\n email=" +email+ 
    "\n address=" +address+ "\n password=" +password+ "\n Phone Number="+ phoneNumber;
  }

}
