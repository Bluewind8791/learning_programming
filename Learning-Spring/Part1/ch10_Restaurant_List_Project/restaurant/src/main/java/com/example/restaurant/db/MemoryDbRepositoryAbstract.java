package com.example.restaurant.db;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

// 추상 클래스
abstract public class MemoryDbRepositoryAbstract<T extends MemoryDbEntity> implements MemoryDbRepositoryIfs<T> {
    
    private final List<T> db = new ArrayList<>();
    private int index = 0;


    @Override
    public Optional<T> findById(int index) {
        return db.stream().filter(it -> it.getIndex() == index).findFirst();
    }

    @Override
    public T save(T entity) {
        
        // 데이터가 있는지 판단
        var optionalEntity = db.stream().filter(it -> it.getIndex() == entity.getIndex()).findFirst();

        if (optionalEntity.isEmpty()) {;
            // db에 데이터 없는 경우 (새로 만드는 경우)
            index++;
            entity.setIndex(index);
            db.add(entity);
            return entity;
        } else { 
            // db에 이미 데이터 있는경우 (update)
            var preIndex = optionalEntity.get().getIndex(); // 이전에 가지고있던 인덱스를 뽑아오고
            entity.setIndex(preIndex); // 새로운 인덱스를 세팅

            deleteById(preIndex); // 기존에 있는 데이터 삭제
            db.add(entity); // 새로 받은 entity를 add
            return entity;
        }
        

    }

    @Override
    public void deleteById(int index) {
        var optionalEntity = db.stream().filter(it -> it.getIndex() == index).findFirst();
        if(optionalEntity.isPresent()) {
            db.remove(optionalEntity.get());
        }
    }

    @Override
    public List<T> findAll() {
        return db;
    }

}
