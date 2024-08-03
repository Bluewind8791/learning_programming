package hello.item_service.domain.item;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Test;

import java.util.List;

import static org.assertj.core.api.Assertions.*;

class ItemRepositoryTest {

    ItemRepository itemRepository = new ItemRepository();

    @AfterEach
    void tearDown() {
        itemRepository.clearStore();
    }

    @Test
    void save() {
        // given
        Item item = new Item("itemA", 10000, 10);

        // when
        Item savedItem = itemRepository.save(item);

        // then
        Item findItem = itemRepository.findById(item.getId());
        assertThat(findItem).isEqualTo(savedItem);
    }

    @Test
    void findAll() {
        Item itemA = new Item("itemA", 10000, 10);
        Item itemB = new Item("itemB", 20000, 20);

        itemRepository.save(itemA);
        itemRepository.save(itemB);

        List<Item> result = itemRepository.findAll();
        assertThat(result.size()).isEqualTo(2);
        assertThat(result).contains(itemA, itemB);
    }

    @Test
    void update() {
        Item itemA = new Item("itemA", 10000, 10);
        Item savedItem = itemRepository.save(itemA);
        Long savedItemId = savedItem.getId();

        Item itemB = new Item("itemB", 20000, 20);
        itemRepository.update(savedItemId, itemB);

        Item findItem = itemRepository.findById(savedItemId);
        assertThat(findItem).isEqualTo(savedItem);
    }
}