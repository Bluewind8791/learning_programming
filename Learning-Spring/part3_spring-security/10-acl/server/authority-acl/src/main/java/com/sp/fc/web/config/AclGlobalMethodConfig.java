package com.sp.fc.web.config;

import javax.sql.DataSource;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.boot.jdbc.DataSourceBuilder;
import org.springframework.cache.annotation.EnableCaching;
import org.springframework.cache.ehcache.EhCacheFactoryBean;
import org.springframework.cache.ehcache.EhCacheManagerFactoryBean;
import org.springframework.context.annotation.Bean;
import org.springframework.security.access.PermissionEvaluator;
import org.springframework.security.access.expression.method.DefaultMethodSecurityExpressionHandler;
import org.springframework.security.access.expression.method.MethodSecurityExpressionHandler;
import org.springframework.security.acls.AclPermissionEvaluator;
import org.springframework.security.acls.domain.AclAuthorizationStrategy;
import org.springframework.security.acls.domain.AclAuthorizationStrategyImpl;
import org.springframework.security.acls.domain.AuditLogger;
import org.springframework.security.acls.domain.ConsoleAuditLogger;
import org.springframework.security.acls.domain.DefaultPermissionGrantingStrategy;
import org.springframework.security.acls.domain.EhCacheBasedAclCache;
import org.springframework.security.acls.jdbc.BasicLookupStrategy;
import org.springframework.security.acls.jdbc.JdbcMutableAclService;
import org.springframework.security.acls.jdbc.LookupStrategy;
import org.springframework.security.acls.model.AclService;
import org.springframework.security.acls.model.PermissionGrantingStrategy;
import org.springframework.security.config.annotation.method.configuration.EnableGlobalMethodSecurity;
import org.springframework.security.config.annotation.method.configuration.GlobalMethodSecurityConfiguration;
import org.springframework.security.core.authority.SimpleGrantedAuthority;


@EnableCaching
@EnableAutoConfiguration
@EnableGlobalMethodSecurity(prePostEnabled = true)
public class AclGlobalMethodConfig extends GlobalMethodSecurityConfiguration {
    
    @Bean
    @ConfigurationProperties(prefix = "spring.datasource")
    public DataSource dataSource() {
        return DataSourceBuilder.create().build();
    }

    @Override
    protected MethodSecurityExpressionHandler createExpressionHandler() {
        DefaultMethodSecurityExpressionHandler expressionHandler = new DefaultMethodSecurityExpressionHandler();
        expressionHandler.setPermissionEvaluator(aclPermissionEvaluator());
        return super.createExpressionHandler();
    }

    private PermissionEvaluator aclPermissionEvaluator() {
        AclPermissionEvaluator permissionEvaluator = new AclPermissionEvaluator(
            aclService()
        );
        return permissionEvaluator;
    }

    private AclService aclService() {
        JdbcMutableAclService aclService = new JdbcMutableAclService(
            dataSource(), 
            lookupStrategy(),
            aclCache()
        );
        return aclService;
    }

    @Bean
    public EhCacheBasedAclCache aclCache() {
        return new EhCacheBasedAclCache(
            aclEhCacheFactoryBean().getObject(), 
            permissionGrantingStrategy(),
            aclAuthorizationStrategy()
        );
    }

    @Bean
    public EhCacheManagerFactoryBean ehCacheFactoryBean() {
        EhCacheManagerFactoryBean factoryBean = new EhCacheManagerFactoryBean();
        return factoryBean;
    }

    @Bean
    public EhCacheFactoryBean aclEhCacheFactoryBean() {
        EhCacheFactoryBean ehCacheFactoryBean = new EhCacheFactoryBean();
        ehCacheFactoryBean.setCacheManager(ehCacheFactoryBean().getObject());
        ehCacheFactoryBean.setCacheName("aclCache");
        return ehCacheFactoryBean;
    }

    @Bean
    PermissionGrantingStrategy permissionGrantingStrategy() {
        return new DefaultPermissionGrantingStrategy(ConsoleAuditLogger());
    }

    @Bean
    AuditLogger ConsoleAuditLogger() {
        return new ConsoleAuditLogger();
    }

    @Bean
    LookupStrategy lookupStrategy() {
        return new BasicLookupStrategy(
            dataSource(), 
            aclCache(), 
            aclAuthorizationStrategy(), 
            ConsoleAuditLogger()
        );
    }

    private AclAuthorizationStrategy aclAuthorizationStrategy() {
        return new AclAuthorizationStrategyImpl(new SimpleGrantedAuthority("ROLE_ADMIN"));
    }
}
