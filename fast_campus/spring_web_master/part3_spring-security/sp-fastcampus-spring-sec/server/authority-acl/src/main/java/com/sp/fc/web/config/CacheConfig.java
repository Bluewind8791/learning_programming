package com.sp.fc.web.config;

import org.springframework.cache.annotation.EnableCaching;
import org.springframework.cache.ehcache.EhCacheCacheManager;
import org.springframework.cache.ehcache.EhCacheManagerFactoryBean;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import java.util.ResourceBundle;


/**
 * EHCache를 사용하는 캐시 설정
 */
@Configuration
@EnableCaching
public class CacheConfig {

    @Bean
    public EhCacheCacheManager cacheManager(){
        EhCacheCacheManager cacheManager = new EhCacheCacheManager();
        cacheManager.setCacheManager(ehcacheFactoryBean().getObject());
        return cacheManager;
    }

    @Bean
    public EhCacheManagerFactoryBean ehcacheFactoryBean() {
        return new EhCacheManagerFactoryBean();
    }

}
